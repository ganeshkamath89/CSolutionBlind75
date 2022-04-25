// NumberOfIslands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	void mark_current_island(vector<vector<char>> &matrix, int x, int y, int r, int c)
	{
		if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != '1')  //Boundary case for matrix
			return;

		//Mark current cell as visited
		matrix[x][y] = '2';

		//Make recursive call in all 4 adjacent directions
		mark_current_island(matrix, x + 1, y, r, c);  //DOWN
		mark_current_island(matrix, x, y + 1, r, c);  //RIGHT
		mark_current_island(matrix, x - 1, y, r, c);  //TOP
		mark_current_island(matrix, x, y - 1, r, c);  //LEFT
	}
public:
	int numIslands(vector<vector<char>>& grid) {

		//For FAST I/O
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int rows = grid.size();
		if (rows == 0)     //Empty grid boundary case
			return 0;
		int cols = grid[0].size();

		//Iterate for all cells of the array
		int no_of_islands = 0;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (grid[i][j] == '1')
				{
					mark_current_island(grid, i, j, rows, cols);
					no_of_islands += 1;
				}
			}
		}
		return no_of_islands;
	}
};

int main()
{
	vector<vector<char>> grid = { 
		{ '1', '1', '0', '0', '0' },
		{ '0', '1', '0', '0', '1' },
		{ '1', '0', '0', '1', '1' },
		{ '0', '0', '0', '0', '0' },
		{ '1', '0', '1', '0', '1' }
	};
	Solution s;
	cout << "Number of islands is: " << s.numIslands(grid);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
