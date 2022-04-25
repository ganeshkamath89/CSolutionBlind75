#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <limits.h>

void RotateImage(int** matrix, int n, int m) {// In a square matrix n = m	
	int t = 0, l = 0, r = n - 1, b = n - 1;
	while (l < r)
	{
		int range = r - l;
		int topLeft = 0;
		for (int i = 0; i < range; i++)
		{
			t = l, b = r;
			topLeft = matrix[t][l + i];
			matrix[t][l + i] = matrix[b - i][l];
			matrix[b - i][l] = matrix[b][r - i];
			matrix[b][r - i] = matrix[t + i][r];
			matrix[t + i][r] = topLeft;
		}
		r--;
		l++;
	}
}

int main() {
	int n = 3, m = 3;
	int** matrix = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)calloc(m, sizeof(int));
	}
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;

	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;

	matrix[2][0] = 7;
	matrix[2][1] = 8;
	matrix[2][2] = 9;

	RotateImage(matrix, n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}