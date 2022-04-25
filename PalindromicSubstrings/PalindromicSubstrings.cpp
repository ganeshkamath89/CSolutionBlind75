#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countPali(const char* s, int len, int l, int r)
{
	int res = 0;
	while (l >= 0 && r < len && s[l] == s[r]) // this loop expands from the center and adds 2 characters every iteration to check for palindrome
	{
		res += 1;
		l -= 1;
		r += 1;
	}
	return res;
}

int longestPalSubstr(const char* str)
{
	int res = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		res += countPali(str, len, i, i); // Odd lengths
		res += countPali(str, len, i, i + 1); // even lengths
	}
	return res;
}

int main()
{
	printf("\nLength is: %d", longestPalSubstr("aaa"));
	return 0;
}