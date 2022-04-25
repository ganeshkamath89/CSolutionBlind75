#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <limits.h>

void setZeroes(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < m; k++)
				{
					if (matrix[i][k] != 0)
					{
						matrix[i][k] = INT_MIN;
					}
				}
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k = 0; k < n; k++)
				{
					if (matrix[k][j] != 0)
					{
						matrix[k][j] = INT_MIN;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == INT_MIN)
			{
				matrix[i][j] = 0;
			}
		}
	}
}
int main() {
	// Example 1
	int n = 3, m = 3;
	int** matrix = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)calloc(m, sizeof(int));
	}
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[0][2] = 1;

	matrix[1][0] = 1;
	matrix[1][1] = 0;
	matrix[1][2] = 1;

	matrix[2][0] = 1;
	matrix[2][1] = 1;
	matrix[2][2] = 1;

	setZeroes(matrix, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	// Example 2

	n = 3, m = 4;
	int** matrix2 = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		matrix2[i] = (int*)calloc(m, sizeof(int));
	}
	matrix2[0][0] = 0;
	matrix2[0][1] = 1;
	matrix2[0][2] = 2;
	matrix2[0][3] = 0;

	matrix2[1][0] = 3;
	matrix2[1][1] = 4;
	matrix2[1][2] = 5;
	matrix2[1][3] = 2;

	matrix2[2][0] = 1;
	matrix2[2][1] = 3;
	matrix2[2][2] = 1;
	matrix2[2][3] = 5;

	setZeroes(matrix2, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}

	return 0;
}