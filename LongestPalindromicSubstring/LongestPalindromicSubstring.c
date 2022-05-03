#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

void printSubStr(const char* str, int start, int window)
{
	char *dest = (char*)calloc((window + 1), sizeof(char)); // Include Null termination
	strncpy(dest, (str + start), window);
	printf("%s", dest);
	free(dest);
}

bool isSubstringPalindrome(const char* str, int start, int end, int len)
{
	for (int k = 0; k < len / 2; k++) {
		if (str[start + k] != str[end - k]) {
			return false; // Not a Palindrome
		}
	}
	return true;
}

int longestPalSubstr(const char* str)
{
	unsigned int n = strlen(str);
	int maxLength = 1, start = 0, window = 0, end = 0;

	// Nested loop to find start and maxLength
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = i; j < n; j++) {
			window = j - i + 1;
			if (isSubstringPalindrome(str, i, j, window))
			{
				if ((window > maxLength))
				{
					maxLength = window;
					start = i;
				}
			}
		}
	}
	printf("\n\nLongest palindrome substring is: ");
	printSubStr(str, start, maxLength);
	return maxLength;
}

int main()
{
	printf("\nLength is: %d", longestPalSubstr("forgeeksskeegfor"));
	printf("\nLength is: %d", longestPalSubstr("aaaabbaa"));
	return 0;
}
