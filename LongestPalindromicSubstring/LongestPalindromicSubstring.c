#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printSubStr(const char* str, int low, int high)
{
	for (int i = low; i <= high; ++i)
	{
		printf("%c", str[i]);
	}
}

int longestPalSubstr(const char* str)
{
	unsigned int n = strlen(str);
	int maxLength = 1, start = 0, len = 0, end = 0;

	// Nested loop to mark start and end index
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = i; j < n; j++) {
			int flag = 1;

			// Check palindrome
			len = j - i + 1;
			for (int k = 0; k < len / 2; k++) {
				if (str[i + k] != str[j - k]) {
					flag = 0;
					break;
				}
			}

			if (flag && (len > maxLength)) {
				maxLength = len;
				start = i;
				end = j;
				printf("\nPalindrome substring: ");
				printSubStr(str, start, end);
			}
		}
	}
	end = start + maxLength - 1;
	printf("\n\nLongest palindrome substring is: ");
	printSubStr(str, start, end);
	return maxLength;
}

int main()
{
	printf("\nLength is: %d", longestPalSubstr("forgeeksskeegfor"));
	printf("\nLength is: %d", longestPalSubstr("aaaabbaa"));
	return 0;
}