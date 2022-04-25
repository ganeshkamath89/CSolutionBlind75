#include "common.h"

bool CanAttendAllMeetings(struct Interval* intervals, int n) {
	intervals = sortIntervals(intervals, n);    //Sort all intervals in ASC order

	int prevEnd = intervals[0].end;
	for (int i = 1; i < n; i++)
	{
		if (intervals[i].start >= prevEnd)
		{
			prevEnd = intervals[i].end;
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	size_t n = 8;
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

	bool attendance = CanAttendAllMeetings(Intervals, n);
	printf("could %s\n", attendance ? "attend" : "not attend");
	return 0;
}