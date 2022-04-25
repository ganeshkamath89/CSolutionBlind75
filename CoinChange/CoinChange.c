#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <stdlib.h>

int coinChange(int* coins, int n, int k)
{
	int** dp = (int**)malloc((n + 1) * sizeof(int*)); // 2D DP table
	for (int i = 0; i < (n + 1); i++)
	{
		dp[i] = (int*)calloc(k + 1, sizeof(int));
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			int c = coins[i - 1];
			if (j == 0)
			{
				dp[i][j] = 0;
			}
			else if (i == 0)
			{
				dp[i][j] = INT_MAX;
			}
			else if (c > j) // this case will prevent dp[i][j - c] from becoming negative indexed
			{
				int exclude = dp[i - 1][j];
				dp[i][j] = exclude; // Because we cannot include a higher coin change to form lower sum
			}
			else
			{
				int include = 1 + dp[i][j - c];
				int exclude = dp[i - 1][j];
				dp[i][j] = min(include, exclude);
			}
		}
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}

	return dp[n][k] == INT_MAX ? -1 : dp[n][k];
}

int coinChange_NeetCode(int* coins, int coin_count, int amount)
{
	int* dp = (int*)calloc((amount + 1), sizeof(int)); // 1D DP table
	for (int i = 0; i < amount + 1; i++)
	{
		dp[i] = INT_MAX;
	}

	dp[0] = 0;
	for (int i = 1; i < amount + 1; i++)
	{
		for (int j = 0; j < coin_count; j++)
		{
			if (i - coins[j] >= 0)
			{
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
			}
		}
	}
	for (int i = 0; i < amount + 1; i++)
	{
		printf("[%d]%d\t", i, dp[i]);
	}
	printf("\n");

	return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
	int n = 3, k = 11;
	int* coins = (int*)calloc(n, sizeof(int));
	coins[0] = 1, coins[1] = 2, coins[2] = 5;
	printf("\n Solution form Tech Dose\n");
	printf("Minimum coins required to form a value %d is: %d\n", k, coinChange(coins, n, k));
	printf("\n Solution form Neet Code\n");
	printf("Minimum coins required to form a value %d is: %d\n", k, coinChange_NeetCode(coins, n, k));
	return 0;
}
