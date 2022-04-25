#include <stdio.h>
#include <stdlib.h>

int LongestConsequitiveSequence(int* arr, int n)
{
	int nums[400] = { 0 };
	for (int i = 0; i < n; i++)
	{
		nums[arr[i]]++;
	}

	int length = 0;
		int tempLen = 0;
	for (int i = 0; i < 400; i++)
	{
		if (nums[i] > 0)
		{
			if (tempLen == 0)
			{
				tempLen++;
			}
			if( nums[i + 1] > 0)
			{
				tempLen++;
			}
		}
		else
		{
			tempLen = 0;
		}
		length = max(length, tempLen);
	}
	return length;
}

int main()
{
	int n = 6;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 100; arr[1] = 4; arr[2] = 3; arr[3] = 2; arr[4] = 200; arr[5] = 1;
	int result = LongestConsequitiveSequence(arr, n);
	printf("Longest consequitive sequence length: %d", result);
}
