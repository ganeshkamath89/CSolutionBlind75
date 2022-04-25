#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Word {
	char* str;
	int index;
};

struct DupArray {
	struct Word* array;
	int size; // Size of array
};

int compStr(const void* a, const void* b)
{
	struct Word *a1 = (struct Word*)a, *b1 = (struct Word*)b;
	return strcmp(a1->str, b1->str);
}

int compare(const void * a, const void * b) {
	return (*(char*)a - *(char*)b);
}

char** createDuplicate(char** wordArr, int n, int k)
{
	char** dupArr = (char**)malloc((n) * sizeof(char*));
	for (int i = 0; i < n + 1; i++)
	{
		dupArr[i] = (char*)calloc((k + 1), sizeof(char));
		strcpy(dupArr[i], wordArr[i]);
		qsort(dupArr[i], n, sizeof(char), compare);
	}
	return dupArr;
}

struct DupArray* createDupArray(char* str[], int size)
{
	struct DupArray* dupArray = (struct DupArray*)malloc(sizeof(struct DupArray));
	dupArray->size = size;
	dupArray->array = (struct Word*)malloc(dupArray->size * sizeof(struct Word));
	for (int i = 0; i < size; ++i) {
		dupArray->array[i].index = i;
		dupArray->array[i].str = (char*)malloc(strlen(str[i]) + 1);
		strcpy(dupArray->array[i].str, str[i]);
	}
	return dupArray;
}

void printAnagramsTogether(char** wordArr, int n, int k)
{
	struct DupArray* dupArray = createDupArray(wordArr, n);
	for (int i = 0; i < n; ++i)
		qsort(dupArray->array[i].str, strlen(dupArray->array[i].str), sizeof(char), compare);
	qsort(dupArray->array, n, sizeof(dupArray->array[0]), compStr);
	for (int i = 0; i < n; ++i)
	{
		printf("%s ", wordArr[dupArray->array[i].index]);
	}
}

int main()
{
	int n = 5, k = 3;
	char** wordArr = (char**)malloc((n) * sizeof(char*));
	for (int i = 0; i < n + 1; i++)
	{
		wordArr[i] = (char*)calloc((k + 1), sizeof(char));
	}
	strcpy(wordArr[0], "cat");
	strcpy(wordArr[1], "dog");
	strcpy(wordArr[2], "tac");
	strcpy(wordArr[3], "god");
	strcpy(wordArr[4], "act");

	printAnagramsTogether(wordArr, n, k);
	return 0;
}
