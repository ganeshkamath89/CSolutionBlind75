#include <stdio.h>
#include <malloc.h>

int* bestTimeToBuyAndSellStock(int* profits, int n)
{
	int buy = 0, sell = 0, maxProfit = 0;
	int l = 0, r = 1;
	while (r < n)
	{
		if (profits[l] < profits[r])
		{
			int profit = profits[r] - profits[l];
			if (profit > maxProfit)
			{
				maxProfit = profit;
				buy = l;
				sell = r;
			}
		}
		else
		{
			l = r;
		}
		r++;
	}
	int* result = (int*)malloc(2 * sizeof(int));
	result[0] = buy;
	result[1] = sell;
	return result;
}

int main()
{
	int n = 6;
	int* profits = (int*)malloc(n * sizeof(int));
	profits[0] = 7; profits[1] = 1; profits[2] = 5; profits[3] = 3; profits[4] = 6; profits[5] = 4;
	int* result = bestTimeToBuyAndSellStock(profits, n);
	printf("Buy and sell indices {%d, %d} give the maximum profit of: %d", result[0], result[1], profits[result[1]] - profits[result[0]]);
}
