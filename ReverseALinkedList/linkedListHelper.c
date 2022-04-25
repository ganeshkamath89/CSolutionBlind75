#include "common.h"

struct node* newNode(int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}

void display(struct node* p)
{
	struct node* temp = p;
	while (temp != NULL)
	{
		printf("Data:%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}