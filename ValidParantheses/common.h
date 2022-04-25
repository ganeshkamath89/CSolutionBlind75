#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
struct stack
{
	int top;
	unsigned size;
	int* array;
};

struct stack* createStack(unsigned size);
bool isEmpty(struct stack* stackElement);
bool isFull(struct stack* stackElement);
void push(struct stack* stackElement, int item);
int pop(struct stack* stackElement);
int peek(struct stack* stackElement);
