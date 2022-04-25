#include <stdio.h>
#include <malloc.h>

int gaussArithmeticProgressionSum(int a1, int an, int n)
{
	return ((n*(a1 + an)) / 2);
}

int twoSum_twoLoops(int* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return gaussArithmeticProgressionSum(0, n, n + 1) - sum;
}

int main()
{
	int n = 3;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 3; arr[1] = 0; arr[2] = 1;
	int result = twoSum_twoLoops(arr, n);
	printf("Missing number is: %d\n", result);
}
