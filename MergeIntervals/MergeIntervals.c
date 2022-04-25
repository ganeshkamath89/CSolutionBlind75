#include "common.h"

int mergeIntervals(struct Interval* intervals, int n) {
	intervals = sortIntervals(intervals, n);    //Sort all intervals in ASC order
	for (int i = 0; i < n - 1; i++)
	{
		if (intervals[i].end < intervals[i + 1].start) // no overlap
		{
			continue;
		}
		else
		{
			intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
			for (int j = i+1; j < n - 1; j++)
			{
				intervals[j] = intervals[j + 1];
			}
			i--;
			n--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("{%d,%d}\t", intervals[i].start, intervals[i].end);
	}
	printf("\n");
	return n;
}

int main()
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
	Intervals[6] = existingInterval;
	existingInterval.start = 5;
	existingInterval.end = 7;
	Intervals[7] = existingInterval;

	int count = mergeIntervals(Intervals, n);
	printf("%d\n", count);
	return 0;
}