#include <stdio.h>
#include <malloc.h>

int* twoSum_twoLoops(int* arr, int n, int k)
{
	int first = 0, second = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == k)
			{
				first = i;
				second = j;
				break;
			}
		}
	}
	int* result = (int*)malloc(2 * sizeof(int));
	result[0] = first;
	result[1] = second;
	return result;
}

int main()
{
	int n = 4, k = 4;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 2; arr[1] = 1; arr[2] = 3; arr[3] = 5;
	int* result = twoSum_twoLoops(arr, n, k);
	printf("Element at indices {%d, %d} sum up to: %d", result[0], result[1], k);
}
