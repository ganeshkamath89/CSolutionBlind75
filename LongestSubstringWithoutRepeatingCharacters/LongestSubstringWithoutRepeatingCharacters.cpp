#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

int WindowSize(int i, int j)
{
	return i - j + 1;
}

bool isPresent(char* temp, char ch)
{
	bool isFound = false;
	for (int i = 0; i < strlen(temp); i++)
	{
		if (ch == temp[i])
		{
			isFound = true;
		}
	}
	return isFound;
}

int LengthOfLongestSubstringWithoutRepeatingCharacters(const char* arr, int len)
{
	int i = 0, j = 0, max = 0;
	char* temp = (char*)calloc(len + 1, sizeof(char));

	for (int i = 0; i < len; i++)
	{
		char ch = arr[i];
		while (isPresent(temp, ch))
		{
			for (int k = 0; k < strlen(temp); k++)
			{
				temp[k] = temp[k + 1];
			}
			j++;
		}
		temp[strlen(temp)] = ch;
		int w = WindowSize(i, j);
		max = w > max ? w : max;
	}
	return max;
}

int main()
{
	const char* arr = "PWWKEW";
	int len = strlen(arr);
	int max = LengthOfLongestSubstringWithoutRepeatingCharacters(arr, len);
	printf("Length Of Longest Substring Without Repeating Characters: %d\n", max);
	return 0;
}
