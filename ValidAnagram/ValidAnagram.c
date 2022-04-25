#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkAnagram(char *s, char *t)
{
	int lenS = strlen(s), lenT = strlen(t);
	if (lenS != lenT)
		return false;

	for (int i = 0; i < lenS; i++)
	{
		if (s[i] != t[i])
		{
			char ch = s[i];
			bool isFound = false;
			int j = i + 1;
			for (; j < lenT; j++)
			{
				if (ch == t[j])
				{
					isFound = true;
					break;
				}
			}
			if (isFound == false)
			{
				return false;
			}
			else
			{
				char temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
	return true;
}

bool checkAnagramCountingSort(char *s, char *t)
{
	int lenS = strlen(s), lenT = strlen(t);
	if (lenS != lenT)
		return false;

	char sCount[26] = { 0 }, tCount[26] = { 0 };

	for (int i = 0; i < lenS; i++)
	{
		sCount[s[i] - 'a']++;
		tCount[t[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (sCount[i] != tCount[i])
		{
			return false;
		}
	}

	return true;
}

void CheckAndSwap()
{

	char s[] = "anagram", t[] = "nagaram";
	char f[] = "file", l[] = "life";
	char rats[] = "rats", star[] = "star";
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagram(s, t) ? "" : "not ", s, t);
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagram(f, l) ? "" : "not ", f, l);
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagram(rats, star) ? "" : "not ", rats, star);
}

void UseCountingSort()
{

	char s[] = "anagram", t[] = "nagaram";
	char f[] = "file", l[] = "life";
	char rats[] = "rats", star[] = "star";
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagramCountingSort(s, t) ? "" : "not ", s, t);
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagramCountingSort(f, l) ? "" : "not ", f, l);
	printf("strings compared are %san anagram pair {%s, %s}\n", checkAnagramCountingSort(rats, star) ? "" : "not ", rats, star);
}

int main()
{
	CheckAndSwap();
	UseCountingSort();
}