#include <stdio.h>
#include <stdlib.h>

int SearchBSRotatedArray(int* arr, int n, int target)
{
	int index;
	int l = 0, r = n - 1, m = 0;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (arr[m] == target)
		{
			index = m;
			break;
		}
		else if (arr[m] >= arr[l]) // Eg: [4 5 6 7 8[M] 0 1 2 3] - search 5
		{
			if (target <= arr[m] && target >= arr[l])
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		else // Eg: [7 8 0 1 2[M] 3 4 5 6]
		{
			if (target >= arr[m] && target <= arr[r]) // Eg: [7 8 0 1 2[M] 3 4 5 6] - search 5
			{
				l = m + 1;
			}
			else  // Eg: [5 6 7 8 0[M] 1 2 3 4] - search 5
			{
				r = m - 1;
			}
		}
	}
	return index;
}

/* Driver program to test above functions*/
int main()
{
	int n = 9;
	int target = 5;
	int* arr = (int*)malloc(n * sizeof(int));
	arr[0] = 4; arr[1] = 5; arr[2] = 6; arr[3] = 7; 
	arr[4] = 8; arr[5] = 0; arr[6] = 1; arr[7] = 2; arr[8] = 3;
	
	int index = SearchBSRotatedArray(arr, n, target);

	printf("\nIndex of element is %d\n", index);
	return 0;
}