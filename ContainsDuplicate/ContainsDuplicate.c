#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

bool containsDuplicate(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n = 6;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 7; arr[1] = 1; arr[2] = 5; arr[3] = 3; arr[4] = 1; arr[5] = 4;
	bool result = containsDuplicate(arr, n);
	printf("Array %s duplicates", result ? "contains" : "does not contain");
}
