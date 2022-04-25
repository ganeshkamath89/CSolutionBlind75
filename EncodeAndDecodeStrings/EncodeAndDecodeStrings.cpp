#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

char* Encode(char** s, int k, int n)
{
	char* finalString = (char*)calloc(n*k + n /*#*/ + 3 * n /*Assuming 3 digit lengths*/, sizeof(char));
	for (int i = 0; i < k; i++)
	{
		int len = strlen(s[i]);
		int temp = len, digits = 0;
		while (temp > 0)
		{
			temp = temp / 10;
			digits++;
		}

		char* encodedString = (char*)calloc((digits + len + 1 + 1), sizeof(char));
		sprintf(encodedString, "%d#%s", len, s[i]);
		sprintf(finalString, "%s%s", finalString, encodedString);
	}
	return finalString;
}

void Decode(const char* s)
{

}

int main()
{
	int n = 5, k = 5;
	char** arr = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)calloc(k, sizeof(char));
	}
	strcpy(arr[0], "lint");
	strcpy(arr[1], "code");
	strcpy(arr[2], "love");
	strcpy(arr[3], "you");

	char* encodedString = Encode(arr, k, n);
	printf("%s\n", encodedString);

	char* newEncodedString = (char*)calloc(n*k + n + 3*n, sizeof(char));
	sprintf(newEncodedString, "%d!%s", n, encodedString);
	printf("%s\n", newEncodedString);
	Decode(newEncodedString);
	return 0;
}