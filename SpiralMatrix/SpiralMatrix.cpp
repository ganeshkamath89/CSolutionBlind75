#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <limits.h>

void spiralTraversal(int** matrix, int n, int m) {
	int t = 0, l = 0, r = m - 1, d = n - 1;
	int dir = 0;
	/*
	0=> l->r
	1=> t->d
	2=> r->l
	3=> d->t
	*/
	while (t <= d && l <= r)
	{
		if (dir == 0)
		{
			for (int j = l; j <= r; j++)
			{
				printf("%d ", matrix[t][j]);
			}
			t++;
		}
		else if (dir == 1)
		{
			for (int i = t; i <= d; i++)
			{
				printf("%d ", matrix[i][r]);
			}
			r--;
		}
		else if (dir == 2)
		{
			for (int j = r; j >= l; j--)
			{
				printf("%d ", matrix[d][j]);
			}
			d--;
		}
		else if (dir == 3)
		{
			for (int i = d; i >= t; i--)
			{
				printf("%d ", matrix[i][l]);
			}
			l++;
		}
		dir = (dir + 1) % 4;
		printf(", ");
	}
	printf("\n\n");
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

	spiralTraversal(matrix, n, m);
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

	spiralTraversal(matrix2, n, m);
	return 0;
}