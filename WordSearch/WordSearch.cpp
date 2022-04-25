#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

// level: index till which pattern is matched 
// x, y: current position in 2D array
bool findmatch(char** mat, const char* pat, int x, int y, int nrow, int ncol, int level)
{
	int l = strlen(pat);
	if (level == l)// Pattern matched
	{
		return true;
	}

	if (x < 0 || y < 0 || x >= nrow || y >= ncol)// Out of Boundary
	{
		return false;
	}

	// If grid matches with a letter while recursion
	if (mat[x][y] == pat[level])
	{
		char temp = mat[x][y];
		mat[x][y] = '#'; // Marking this cell as visited

		// finding subpattern in 4 directions
		bool res = findmatch(mat, pat, x - 1, y, nrow, ncol, level + 1) ||
			findmatch(mat, pat, x + 1, y, nrow, ncol, level + 1) ||
			findmatch(mat, pat, x, y - 1, nrow, ncol, level + 1) ||
			findmatch(mat, pat, x, y + 1, nrow, ncol, level + 1);

		mat[x][y] = temp;// marking this cell as unvisited again
		return res;
	}
	else // Not matching then false
	{
		return false;
	}
}

bool WordSearch(char** mat, const char* pat, int nrow, int ncol)
{
	int l = strlen(pat);
	if (l > nrow * ncol)// if total characters in matrix is less then pattern length
		return false;

	for (int i = 0; i < nrow; i++) { // Traverse in the grid
		for (int j = 0; j < ncol; j++) {
			if (mat[i][j] == pat[0])// If first letter matches, then recur and check
				if (findmatch(mat, pat, i, j, nrow, ncol, 0))
					return true;
		}
	}
	return false;
}

int main()
{
	int r = 5, c = 5;
	char** matrix = (char**)malloc(r * sizeof(char*));
	for (int i = 0; i < r; i++)
	{
		matrix[i] = (char*)calloc(c, sizeof(char));
	}
	matrix[0][0] = 'a';
	matrix[0][1] = 'x';
	matrix[0][2] = 'm';
	matrix[0][3] = 'y';

	matrix[1][0] = 'b';
	matrix[1][1] = 'g';
	matrix[1][2] = 'd';
	matrix[1][3] = 'f';

	matrix[2][0] = 'x';
	matrix[2][1] = 'e';
	matrix[2][2] = 'e';
	matrix[2][3] = 't';

	matrix[3][0] = 'r';
	matrix[3][1] = 'a';
	matrix[3][2] = 'k';
	matrix[3][3] = 's';

	printf("%s", (WordSearch(matrix, "geeks", r, c)) ? "Yes" : "No");
	return 0;
}