#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int LongestIncreasingSubsequence(int* arr, int n)
{
	int* lis = (int*)calloc(n, sizeof(int));
	lis[0] = 1;

	int maxLen = 0;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				maxLen = max(maxLen, lis[i]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d\t", lis[i]);
	}
	printf("\n");

	int temp = maxLen;
	int* sequence = (int*)calloc(temp, sizeof(int));
	int maximum = n - 1;
	for (int i = maximum; i >= 0 && temp >= 0; i--)
	{
		if (lis[i] == temp)
		{
			printf("%d\t", arr[i]);
			sequence[temp - 1] = arr[i];
			maximum = i;
			temp--;
		}
	}
	printf("\n");

	return maxLen;
}

int main()
{
	int n = 5;
	int* arr = (int*)calloc(n, sizeof(int));
	arr[0] = 5, arr[1] = 8, arr[2] = 7, arr[3] = 1, arr[4] = 9;
	printf("LIS of arr is of length: %d", LongestIncreasingSubsequence(arr, n));
	return 0;
}