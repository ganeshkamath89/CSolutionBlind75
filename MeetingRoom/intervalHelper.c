#include "common.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void swap(int* a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool doesOverlap(struct Interval a, struct Interval b)
{
	return (min(a.end, b.end) >= max(a.start, b.start));
}

struct Interval* sortIntervals(struct Interval* intervals, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (intervals[j].start > intervals[j + 1].start)
			{
				int temp = intervals[j].start;
				intervals[j].start = intervals[j + 1].start;
				intervals[j + 1].start = temp;

				temp = intervals[j].end;
				intervals[j].end = intervals[j + 1].end;
				intervals[j + 1].end = temp;
			}
		}
	}
	return intervals;
}