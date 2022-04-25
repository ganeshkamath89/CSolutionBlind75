#include <stdio.h>
#include <malloc.h>
int* getSetBitCount(int* a, int a_count)
{
	int* dp = (int*)calloc(a_count, sizeof(int));
	dp[0] = 0;
	printf("Start with 0\n");
	for (int i = 1; i < a_count; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d is even so we copy value of x/2[%d] %d to give %d\n", i, i/2, dp[i/2], dp[i/2]);
		}
		else
		{
			printf("%d is odd so we copy value of x/2[%d] %d and add 1 to give %d\n", i, i/2, dp[i / 2], dp[i / 2] + 1);
		}
		dp[i] = dp[i / 2] + i % 2;
	}
	return dp;
}
int main()
{
	int a = 8;
	int range = a + 1; /*0 - 8*/
	int* arr = (int*)calloc(range, sizeof(int));
	int* result = getSetBitCount(arr, range);
	for (int i = 0; i < range; i++)
	{
		printf("%d\t", result[i]);
	}
	return 0;
}