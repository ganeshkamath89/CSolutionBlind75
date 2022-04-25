#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// Program: Given a digit sequence of length n, returns count of possible decodings by replacing 1 with A, 2 with B, ... 26 with Z

int decodeWays_DP(char *digits, int n)
{
	if (digits[0] == '0')
		return 0;
	int* dp = (int *)calloc(n + 1, sizeof(int));
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 0;
		if (digits[i - 1] > '0') // digit should be greater than 0, between 1 and 9
			dp[i] = dp[i - 1];
		if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 1] < '7')) // 10 to 26
			dp[i] += dp[i - 2];
	}
	return dp[n];
}

int decodeWays(char* arr, int n)
{
	if (n == 0 || n == 1)
		return 1;
	if (arr[0] == '0')
		return 0;

	int res = 0;
	if (arr[n - 1] > '0') // digit should be greater than 0, between 1 and 9
	{
		res = decodeWays(arr, n - 1);
	}	
	if (arr[n - 2] == '1' || (arr[n - 2] == '2' && arr[n - 1] < '7')) // 2nd digit numbers can be between 10 and 26
	{
		res += decodeWays(arr, n - 2);
	}
	return res;
}

int countWays(char* digits, int n)
{
	if (n == 0 || (n == 1 && digits[0] == '0'))
		return 0;
	return decodeWays(digits, n);
}

int main()
{
	char arr[] = "121";
	/*
	121 => 1, 2, 1
	121 => 12, 1
	121 => 1, 21
	therefore 3 ways
	*/
	int result = countWays(arr, strlen(arr));
	printf("Using Recursion: %d\n", result);

	result = decodeWays_DP(arr, strlen(arr));
	printf("Using Dynamic Programming: %d\n", result);
	return 0;
}
