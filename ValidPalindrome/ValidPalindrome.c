#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char s)
{
	if ((s >= 'a' && s <= 'z') ||
		(s >= 'A' && s <= 'Z') ||
		(s >= '0' && s <= '9'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isPalindrome(const char* str)
{
	int len = strlen(str);
	if (len == 0)
	{
		return true;
	}
	int start = 0, end = len - 1;
	while (start < end)
	{
		while (!isValid(str[start]) && start < end)
		{
			start++;
		}
		while (!isValid(str[end]) && start < end)
		{
			end--;
		}
		if (str[start] != str[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

int main()
{
	printf("%s", isPalindrome("a$$bba") ? "Valid\n" : "Invalid\n");
	printf("%s", isPalindrome("abbccbba") ? "Valid\n" : "Invalid\n");
	printf("%s", isPalindrome("geeks") ? "Valid\n" : "Invalid\n");
	printf("%s", isPalindrome("a man, a plan, a canal. panama") ? "Valid\n" : "Invalid\n");
	return 0;
}
