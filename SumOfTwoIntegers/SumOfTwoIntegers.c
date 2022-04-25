#include <stdio.h>
int getSum(int a, int b)
{
	while (b != 0)
	{
		int carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}
	return a;
}

int main()
{
	int a = 9, b = 11;
	printf("Sum: %d", getSum(a, b));
}
