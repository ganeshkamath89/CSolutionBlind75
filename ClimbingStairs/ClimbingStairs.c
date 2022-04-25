#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countCombinations(int n)
{
	int one = 1, two = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int temp = one;
		one = one + two;
		two = temp;
	}
	return one;
}

int binetsFormula(int n)
{
	int m = n + 1;
	double sqrt5 = sqrt(5);
	return (int)((1.0 / (pow(2,m)*sqrt5))* (pow((1.0 + sqrt5), m) - pow((1.0 - sqrt5), m)));
}

int main()
{
	int stairs = 5;
	printf("Number of ways to climb %d stairs: %d\n", stairs, countCombinations(stairs));
	printf("Number of ways to climb %d stairs[Binet's formula]: %d\n", stairs, binetsFormula(stairs));
	return 0;	
}
