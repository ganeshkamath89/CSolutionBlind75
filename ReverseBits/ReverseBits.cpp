#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

char* toBinary(int n)
{
	int len = 32;
	char* binary = (char*)calloc(len+1, sizeof(char));
	int index = 0;
	for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
		binary[index++] = (n & i) ? '1' : '0';
	}
	return binary;
}

int getReverse(int n)
{
	int result = 0;
	int mask = 1;
	for(int i = 0; i < 32; i++)
	{
		int bit = n & mask;
		n = n >> 1;
		result = result | (bit << (31 - i));
	}
	return result;
}

int main()
{
	int n = 4;
	/*
IP: Binary: 00000000000000000000000000000100 ;Num: 4
OP: Binary: 00100000000000000000000000000000 ;Num: 536870912
	*/
	int reverse = getReverse(n);
	printf("IP: Binary: %s ;Num: %d\n", toBinary(n), n);
	printf("OP: Binary: %s ;Num: %d\n", toBinary(reverse), reverse);
}
