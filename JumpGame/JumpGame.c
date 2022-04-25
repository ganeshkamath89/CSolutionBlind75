#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

bool jumpGame(int* arr, int n)
{
	int reachable = 0;
	for (int i = 0; i < n; i++)
	{
		if (reachable < i) // if reachable value is less then index then the index cannot be reached
		{
			return false;
		}
		reachable = max(reachable, i + arr[i]);
		if (reachable >= n - 1) // if at least one value reached last index then it is possible to reach the end
			break;
	}
	return true;
}

int main()
{
	int n = 10;
	int* arr = (int*)calloc(n, sizeof(int));
	arr[0] = 1, arr[1] = 1, arr[2] = 2; arr[3] = 5; arr[4] = 2;
	arr[5] = 1, arr[6] = 0, arr[7] = 0; arr[8] = 1; arr[9] = 3;
	printf("Reachability: %s\n", jumpGame(arr, n) ? "Yes" : "No");
	arr[3] = 3; // Change 5 to 3 to minimize jump
	printf("Reachability: %s\n", jumpGame(arr, n) ? "Yes" : "No");
	return 0;
}
