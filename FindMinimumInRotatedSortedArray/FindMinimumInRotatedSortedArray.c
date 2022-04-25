#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
int min(int a, int b)
{
	return a < b ? a : b;
}
int findMinimum_Alternative(int* arr, int n)
{
	int result = arr[0];
	int l = 0, r = n - 1;
	while (l < r)
	{
		int m = l + (r - l) / 2;
		result = min(result, arr[m]);
		if (arr[m] > arr[r])
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	return arr[l];
}
int findMinimum(int* arr, int n)
{
	int result = arr[0];
	int l = 0, r = n - 1;
	while (l <= r)
	{
		if (arr[l] < arr[r])
		{
			result = min(result, arr[l]);
			return result;
		}
		else
		{
			int m = l + (r - l) / 2;
			result = min(result, arr[m]);
			if (arr[m] >= arr[l])
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}
	return arr[l];
}

int main()
{
	int n = 5;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 3; arr[1] = 4; arr[2] = 5; arr[3] = 1; arr[4] = 2;
	int result = findMinimum(arr, n);
	printf("%d\t", result);
	printf("\n");

	result = findMinimum_Alternative(arr, n);
	printf("%d\t", result);
	printf("\n");
}
