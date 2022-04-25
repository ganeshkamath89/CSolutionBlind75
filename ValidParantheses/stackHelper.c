#include "common.h"

struct stack* createStack(unsigned size)
{
	struct stack* stackElement = (struct stack*)malloc(sizeof(struct stack));
	stackElement->top = -1;
	stackElement->size = size;
	stackElement->array = (int*)malloc(size * sizeof(int));
	return stackElement;
}

bool isEmpty(struct stack* stackElement)
{
	return (stackElement->top == -1);
}

bool isFull(struct stack* stackElement)
{
	return (stackElement->top == (stackElement->size - 1));
}

void push(struct stack* stackElement, int item)
{
	if (isFull(stackElement))
	{
		printf("Stack full. Skipping push.\n");
		return;
	}
	stackElement->array[++(stackElement->top)] = item;
}

int pop(struct stack* stackElement)
{
	if (isEmpty(stackElement))
	{
		printf("stack is empty. pop aborted.\n");
		return -1;
	}
	int item = stackElement->array[(stackElement->top)--];
	return item;
}

int peek(struct stack* stackElement)
{
	if (isEmpty(stackElement))
	{
		printf("stack is empty. peek aborted.\n");
		return -1;
	}
	int item = stackElement->array[(stackElement->top)];
	return item;
}
