#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Interval
{
	int start;
	int end;
};

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


int nonOverlappingInterval(struct Interval* intervals, int n) {
	intervals = sortIntervals(intervals, n);    //Sort all intervals in ASC order
	int count = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (intervals[i].end <= intervals[i + 1].start) // no overlap
		{
			continue;
		}
		else if (intervals[i].end >= intervals[i + 1].end) // first one ends after or whith second one - remove first one
		{
			for (int j = i; j < n - 1; j++)
			{
				intervals[j] = intervals[j + 1];
			}
			n--;
		}
		else if ((intervals[i].start == intervals[i + 1].start) &&
			(intervals[i].end <= intervals[i + 1].end))  // first and second start together but first ends before second - remove second
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				intervals[j] = intervals[j + 1];
			}
			i--; // i'th index should get compared again
			n--;
		}
		else if ((intervals[i].start < intervals[i + 1].start) &&
			(intervals[i].end < intervals[i + 1].end))  // first and second start and end in order - remove one with greater width or comes after
		{
			int j = 0;
			if ((intervals[i].end - intervals[i].start) > (intervals[i + 1].end - intervals[i + 1].start))
			{
				j = i;
			}
			else // even if the widths are equal, remove the second one to prevent other intervals from interfering
			{
				j = i + 1;
			}
			i--;  // i'th index should get compared again

			for (; j <= n - 1; j++)
			{
				intervals[j] = intervals[j + 1];
			}
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

int countMinimumIntervalsToRemove(struct Interval* intervals, int n) {
	intervals = sortIntervals(intervals, n);    //Sort all intervals in ASC order

	int res = 0;
	int prevEnd = intervals[0].end;
	for (int i = 1; i < n; i++)
	{
		if (intervals[i].start >= prevEnd)
		{
			prevEnd = intervals[i].end;
		}
		else
		{
			res += 1;
			prevEnd = min(prevEnd, intervals[i].end);
		}
	}
	return res;
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

	int count = nonOverlappingInterval(Intervals, n);
	printf("%d\n", count);
	count = countMinimumIntervalsToRemove(Intervals, n);
	printf("Count Minimum Intervals To Remove: %d\n", count);
	return 0;
}