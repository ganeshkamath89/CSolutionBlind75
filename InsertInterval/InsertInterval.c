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

bool doesOverlap(struct Interval a, struct Interval b)
{
	return (min(a.end, b.end) >= max(a.start, b.start));
}

struct Interval* insertNewInterval(struct Interval* Intervals, size_t n, struct Interval newInterval, int *count)
{
	struct Interval* ans = (struct Interval*)malloc((n + 1) * sizeof(struct Interval));
	if (n == 0)// If set is empty then simply insert newInterval and return.
	{
		ans[(*count)++] = newInterval;
		return ans;
	}

	// Case 1 and Case 2 (new interval to be inserted at corners)
	bool case1 = newInterval.end < Intervals[0].start, case2 = newInterval.start > Intervals[n - 1].end;
	if (case1 || case2)
	{
		if (case1)
		{
			ans[(*count)++] = newInterval;
		}
		for (size_t i = 0; i < n; i++)
		{
			ans[(*count)++] = Intervals[i];
		}
		if (case2)
		{
			ans[(*count)++] = newInterval;
		}
		return ans;
	}

	// Case 3 (New interval covers all existing)
	bool case3 = newInterval.start <= Intervals[0].start && newInterval.end >= Intervals[n - 1].end;
	if (case3)
	{
		ans[(*count)++] = newInterval;
		return ans;
	}

	// Case 4 and Case 5: These two cases need to check whether intervals overlap or not. For this we can use a subroutine that will perform this function.
	bool overlap = true;
	for (size_t i = 0; i < n; i++)
	{
		overlap = doesOverlap(Intervals[i], newInterval);
		if (!overlap)
		{
			ans[(*count)++] = Intervals[i];
			// Case 4 : To check if given interval lies between two intervals.
			if (newInterval.start > Intervals[i].end && newInterval.end < Intervals[i + 1].start)
			{
				ans[(*count)++] = newInterval;
			}
			continue;
		}
		// Case 5 : Merge Overlapping Intervals. Starting time of new merged interval is minimum of starting time of both overlapping intervals.
		struct Interval temp;
		temp.start = min(newInterval.start, Intervals[i].start);		
		while (i < n && overlap)// Traverse the set until intervals are overlapping
		{
			// Ending time of new merged interval is maximum of ending time of both overlapping intervals.
			temp.end = max(newInterval.end, Intervals[i].end);
			if (i == n - 1)
			{
				overlap = false;
			}
			else
			{
				overlap = doesOverlap(Intervals[i + 1], newInterval);
			}
			i++;
		}
		i--;
		ans[(*count)++] = temp;
	}
	return ans;
}

int main()
{
	size_t n = 5;
	struct Interval* Intervals = (struct Interval*)malloc(n * sizeof(struct Interval));

	struct Interval existingInterval;
	existingInterval.start = 1;
	existingInterval.end = 2;
	Intervals[0] = existingInterval;
	existingInterval.start = 3;
	existingInterval.end = 5;
	Intervals[1] = existingInterval;
	existingInterval.start = 6;
	existingInterval.end = 7;
	Intervals[2] = existingInterval;
	existingInterval.start = 8;
	existingInterval.end = 10;
	Intervals[3] = existingInterval;
	existingInterval.start = 12;
	existingInterval.end = 16;
	Intervals[4] = existingInterval;

	struct Interval newInterval;
	newInterval.start = 4;
	newInterval.end = 9;

	int count = 0;
	struct Interval* ans = insertNewInterval(Intervals, n, newInterval, &count);
	for (size_t i = 0; i < count; i++)
	{
		printf("%d, %d\n", ans[i].start, ans[i].end);
	}
	return 0;
}