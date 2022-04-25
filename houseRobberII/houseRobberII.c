#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int houseRobber(int* arr, int n, int skipIndex)
{
	int one = 0, two = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == skipIndex)
			continue;
		int temp = max(arr[i] + one, two);
		one = two;
		two = temp;
	}
	return two;
}

int houseRobberII(int* arr, int n)
{
	if (n == 1)
		return arr[0];
	int excludingStart = houseRobber(arr, n, 0);
	int excludingEnd = houseRobber(arr, n, n - 1);
	return max(excludingStart, excludingEnd);
}

int main()
{
	int n = 3;
	int* houses = (int*)calloc(n, sizeof(int));
	houses[0] = 2, houses[1] = 3, houses[2] = 2;
	printf("Maximum loot: %d", houseRobberII(houses, n));
	return 0;
}
