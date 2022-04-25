#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <stdlib.h>

int LCS(const char* a, const char* b)
{
	int n = strlen(a);
	int k = strlen(b);
	int** dp = (int**)malloc((n + 1) * sizeof(int*)); // 2D DP table
	for (int i = 0; i < (n + 1); i++)
	{
		dp[i] = (int*)calloc(k + 1, sizeof(int));
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 0;
			}
			else if (i == 0)
			{
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1])
			{
				int match = 1 + dp[i - 1][j - 1];
				dp[i][j] = match;
			}
			else
			{
				int sameRow = dp[i][j - 1];
				int sameCol = dp[i - 1][j];
				dp[i][j] = max(sameRow, sameCol);
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

	printf("\nLongest Common Subsequence string:");
	int lcsLength = dp[n][k];
	char* lcs = (char*)calloc(lcsLength + 1, sizeof(char));
	int i = n, j = k;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1]) // Use the original strings to fill lcs
		{
			lcs[lcsLength - 1] = a[i - 1];
			i--; j--; // Move Diagonally
			lcsLength--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1])
		{
			i--; // Move Left: when top element is greater than or equal to left element
		}
		else
		{
			j--; // Move top
		}
	}
	printf("%s", lcs);
	free(lcs);
	printf("\n");

	return dp[n][k];
}

int main()
{
	char a[] = "ABCDGH";
	char b[] = "AEDFHR";
	printf("\n Solution form Tech Dose\n");
	printf("Length of LCS is: %d\n", LCS(a, b));
	return 0;
}
