#include "common.h"
#include "MeetingRoomII.h"

int* getSortedStartIntervals(struct Interval* intervals, int n)
{
	int *startArr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		startArr[i] = intervals[i].start;
	}
	quickSort(startArr, 0, n - 1);
	return startArr;
}

int* getSortedEndIntervals(struct Interval* intervals, int n)
{
	int *endArr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		endArr[i] = intervals[i].end;
	}
	quickSort(endArr, 0, n - 1);
	return endArr;
}

int maximumMeetingRoomsNeeded(struct Interval* intervals, int n) {
	int *startArr = getSortedStartIntervals(intervals, n), *endArr = getSortedEndIntervals(intervals, n);
	int maxCount = 0, count = 0;
	int s = 0, e = 0;
	while (s < n)
	{
		if (startArr[s] < endArr[e])
		{
			s++;
			count++;
		}
		else
		{
			e++;
			count--;
		}
		maxCount = max(maxCount, count);
	}
	return maxCount;
}

void TestCase1()
{
	size_t n = 3;
	struct Interval* Intervals = (struct Interval*)malloc(n * sizeof(struct Interval));

	struct Interval existingInterval;
	existingInterval.start = 0;
	existingInterval.end = 30;
	Intervals[0] = existingInterval;
	existingInterval.start = 5;
	existingInterval.end = 10;
	Intervals[1] = existingInterval;
	existingInterval.start = 15;
	existingInterval.end = 20;
	Intervals[2] = existingInterval;

	int count = maximumMeetingRoomsNeeded(Intervals, n);
	printf("maximum meeting rooms needed %d\n", count);
}

void TestCase2()
{

	size_t n = 8;
	struct Interval* Intervals = (struct Interval*)malloc(n * sizeof(struct Interval));

	struct Interval existingInterval;
	existingInterval.start = 2;
	existingInterval.end = 3;
	Intervals[0] = existingInterval;
	existingInterval.start = 1;
	existingInterval.end = 3;
	Intervals[1] = existingInterval;
	existingInterval.start = 1;
	existingInterval.end = 2;
	Intervals[2] = existingInterval;
	existingInterval.start = 3;
	existingInterval.end = 4;
	Intervals[3] = existingInterval;
	existingInterval.start = 2;
	existingInterval.end = 4;
	Intervals[4] = existingInterval;
	existingInterval.start = 4;
	existingInterval.end = 6;
	Intervals[5] = existingInterval;
	existingInterval.start = 5;
	existingInterval.end = 8;
	Intervals[5] = existingInterval;
	existingInterval.start = 5;
	existingInterval.end = 7;
	Intervals[5] = existingInterval;

	int count = maximumMeetingRoomsNeeded(Intervals, n);
	printf("maximum meeting rooms needed %d\n", count);
}

int main()
{
	TestCase1();
	TestCase2();
	return 0;
}