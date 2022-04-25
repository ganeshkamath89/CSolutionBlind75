#include <stdio.h>
#include <malloc.h>

int uniquePaths(int m, int n)
{
	int** dp = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		dp[i] = (int*)calloc(n, sizeof(int));
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0) // top corner and left corner have just 1 option
			{
				dp[i][j] = 1;
			}
			else // Assuming star moving to robot
			{
				dp[i][j] =	dp[i - 1][j] +	// Left
							dp[i][j - 1];	// Top
			}
		}
	}
	return dp[m - 1][n - 1];
}

int main()
{
	int output = uniquePaths(3, 4);
	printf("Unique paths: %d", output);
	return 0;
}
