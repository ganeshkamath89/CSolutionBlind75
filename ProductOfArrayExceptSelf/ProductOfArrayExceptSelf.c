#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* containsDuplicate(int* arr, int n)
{
	int *left = (int*)calloc(n, sizeof(int)), *right = (int*)calloc(n, sizeof(int));
	left[0] = arr[0];
	right[n - 1] = arr[n - 1];
	for (int i = 1; i < n ; i++)
	{
		left[i] = left[i - 1] * arr[i];
		right[n - i - 1] = right[n - i] * arr[n - i - 1];
	}

	int* result = (int*)calloc(n, sizeof(int));
	int i = 0;
	result[i] = right[i+1]; // first element
	i++;
	while (i < n - 1)
	{
		result[i] = left[i - 1] * right[i + 1];
		i++;
	}
	result[i] = left[i - 1]; // last element
	return result;
}

int* containsDuplicate_SpaceOptimized(int* arr, int n)
{
	int* result = (int*)calloc(n, sizeof(int));
	result[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		result[i] = result[i - 1] * arr[i];
	}
	int product = 1;
	for (int i = n - 1; i > 0; i--)
	{
		result[i] = result[i - 1] * product; // last element will remain unaffected because of *1 (product is initialized to 1)
		product *= arr[i];
	}
	result[0] = product; // first element
	return result;
}

int main()
{
	int n = 6;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 7; arr[1] = 1; arr[2] = 5; arr[3] = 3; arr[4] = 1; arr[5] = 4;
	int* result = containsDuplicate(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", result[i]);
	}
	free( result);
	printf("\n");

	result = containsDuplicate_SpaceOptimized(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", result[i]);
	}
	free(result);
	printf("\n");
}
