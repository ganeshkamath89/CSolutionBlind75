#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int WindowSize(int i, int j)
{
	return i - j + 1;
}

bool isWindowExceedsK(int window, int maxCount, char k)
{
	return ((window - maxCount) > k);
}

int LongestRepeatingCharacterReplacement(const char* s, int k)
{
	int maxCount = 0;
	int ans = 0;
	int n = strlen(s);
	int cnt[26] = { 0 };
	int j = 0;
	for (int i = 0; i < n; i++) { // i is the right index which gets current character
		int index = s[i] - 'A';
		cnt[index]++; // Add the character to the Window
		maxCount = max(maxCount, cnt[index]); // Check if addition of character increases maxCount
		while (j <= i && isWindowExceedsK(WindowSize(i, j), maxCount, k)) { // Check if Window and max count meet criteria
			--cnt[index]; // If they fall outside, then decrement count;
			j++; // increment left index
		}
		ans = max(ans, WindowSize(i, j));
	}
	return ans;
}

int main()
{
	const char* s = "ABAB";
	int k = 2;
	int len = LongestRepeatingCharacterReplacement(s, k);
	printf("Length Of Longest Repeating Character Replacement: %d\n", len);
	return 0;
}
