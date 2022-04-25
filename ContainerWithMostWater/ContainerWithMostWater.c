#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int maxContainerArea(int* value, int n)
{
	int l = 0; int r = n - 1;
	int maxArea = 0;
	int spotArea = 0;
	while (l < r)
	{
		spotArea = (r - l) * min(value[r], value[l]);
		maxArea = max(maxArea, spotArea);
		if (value[r] < value[l])
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	return maxArea;
}

int main()
{
	int n = 9;
	int* value = (int*)malloc(n * sizeof(int));
	value[0] = 1; value[1] = 8; value[2] = 6; value[3] = 2;
	value[4] = 5; value[5] = 4; value[6] = 8; value[7] = 3; value[8] = 7;
	int area = maxContainerArea(value, n);
	printf("Highest area that can be formed: %d\n", area);
}
