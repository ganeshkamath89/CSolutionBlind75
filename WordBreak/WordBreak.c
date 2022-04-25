#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char* substr(const char *src, int m, int len)
{
	char *dest = (char*)calloc((len + 1), sizeof(char));
	strncpy(dest, (src + m), len);// start with m'th char and copy len chars into the destination
	return dest;
}

bool wordBreak(const char* s, char** wordDict, unsigned int countWords) {
	int n = strlen(s);
	bool** dp = (bool**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = (bool*)calloc((n + 1), sizeof(int));
	}
	for (int length = 1; length <= n; ++length) //Window Size
	{
		int start = 1;
		int end = length;
		while (end <= n) //Sliding Window
		{
			char* temp = substr(s, start - 1, length);
			bool foundWord = false;
			for (unsigned int i = 0; i < countWords; i++)
			{
				if (strlen(temp) != strlen(wordDict[i]))
				{
					continue;
				}
				if (strcmp(temp, wordDict[i]) == 0)
				{
					foundWord = true;
					break;
				}
			}
			if (foundWord)
			{
				dp[start][end] = true;
			}
			else
			{
				bool flag = false;
				for (int i = start; i < end; ++i)
				{
					if (dp[start][i] && dp[i + 1][end])
					{
						flag = true;
						break;
					}
				}
				dp[start][end] = flag;
			}
			start += 1;
			end += 1;
		}
	}
	return dp[1][n];
}

int main()
{
	int wordCount = 2;
	char** myset = (char**)malloc(wordCount * sizeof(char*));
	for (unsigned int i = 0; i < wordCount; i++)
	{
		myset[i] = (char*)calloc(10, sizeof(char));
	}
	strcpy(myset[0], "my");
	strcpy(myset[1], "pen");

	printf("%s", wordBreak("mypenmy", myset, wordCount) ? "True" : "False");
	printf("\n");
	return 0;
}