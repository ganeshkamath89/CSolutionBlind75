#include <stdio.h>
int getNumberOf1Bits_Optimized(int a)
{
	int count = 0;
	while (a != 0)
	{
		a &= (a - 1);
		count++;
	}
	return count;
}

int getNumberOf1Bits(int a)
{
	int count = 0;
	while (a != 0)
	{
		count += a % 2;
		a >>= 1;
	}
	return count;
}

int main()
{
	int a = 9; // 1001
	printf("Bit count of 1 : %d\n", getNumberOf1Bits(a));
	printf("Bit count of 1 : %d\n", getNumberOf1Bits_Optimized(a));
}
