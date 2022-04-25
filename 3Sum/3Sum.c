#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int* Sum3(int* arr, int n, int k, int* count)
{
	qsort(arr, n, sizeof(int), cmpfunc);
	int* result = (int*)malloc(3*10 * sizeof(int)); // assuming we find a maximum of 10 triplets
	int l = 0, r = 0;
	int threeSum = 0;
	*count = 0;
	for (int i = 0; i < n; i++)
	{
		int a = arr[i];
		if (i > 0 && a == arr[i - 1])
		{
			continue;
		}
		l = i + 1;
		r = n - 1;
		while (l < r)
		{
			threeSum = a + arr[l] + arr[r];
			if (threeSum > k)
			{
				r--;
			}
			else if (threeSum < k)
			{
				l++;
			}
			else
			{
				result[(*count) * 3 + 0] = a;
				result[(*count) * 3 + 1] = arr[l];
				result[(*count) * 3 + 2] = arr[r];
				(*count)++;
				l++;
				while (arr[l] == arr[l - 1] && l < r)
				{
					l++;
				}
			}
		}
	}
	return result;
}

int main()
{
	int n = 8, k = 20;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 12; arr[1] = 5; arr[2] = 23; arr[3] = 3;
	arr[4] = 4; arr[5] = 2; arr[6] = 25; arr[7] = 14;
	int count = 0;
	int* result = Sum3(arr, n, k, &count);
	for (int i = 0; i < count; i++)
	{
		printf("Element {%d, %d, %d} sum up to: %d\n", result[3*i + 0 ], result[3 * i + 1], result[3 * i + 2], k);
	}
}
