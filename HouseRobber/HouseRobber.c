#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int houseRobber(int* arr, int n)
{
	int one = 0, two = 0;	
	for (int i = 0; i < n; i++)
	{
		int temp = max(arr[i] + one, two);
		one = two;
		two = temp;
	}
	return two;
}

int main()
{
	int n = 4;
	int* houses = (int*)calloc(n, sizeof(int));
	houses[0] = 1, houses[1] = 2, houses[2] = 3, houses[3] = 1;
	printf("Maximum loot: %d", houseRobber(houses, n));
	return 0;
}
