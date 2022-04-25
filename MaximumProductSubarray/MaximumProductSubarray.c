#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int greatest(int a, int b, int c)
{
	return max(max(a, b), c);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int smallest(int a, int b, int c)
{
	return min(min(a, b), c);
}

int maximumProductSubarray(int* arr, int n)
{
	int maxProd = arr[0], curMax = 1, curMin = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			curMax = curMin = 1;
		}
		int prodMax = arr[i]*curMax, prodMin = arr[i]*curMin;
		curMax = greatest(prodMax, prodMin, arr[i]);
		curMin = smallest(prodMax, prodMin, arr[i]);
		maxProd = max(maxProd, curMax);
	}
	return maxProd;
}

int main()
{
	int n = 6;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = -2; arr[1] = 1; arr[2] = -3; arr[3] = 4; arr[4] = 0; arr[5] = 20;
	int result = maximumProductSubarray(arr, n);
	printf("%d\t", result);
	printf("\n");
}
