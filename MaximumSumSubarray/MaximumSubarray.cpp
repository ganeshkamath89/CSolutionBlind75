#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int maximumSubarray(int* arr, int n)
{
	int maxSum = arr[0];
	int curSum = 0;

	for (int i = 0; i < n; i++)
	{
		if (curSum < 0)
			curSum = 0;
		curSum += arr[i];
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}

int main()
{
	int n = 9;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = -2; arr[1] = 1; arr[2] = -3; arr[3] = 4; arr[4] = -1;
	arr[5] = 2; arr[6] = 1; arr[7] = -5; arr[8] = 4;
	int result = maximumSubarray(arr, n);
	printf("%d\t", result);
	printf("\n");
}
