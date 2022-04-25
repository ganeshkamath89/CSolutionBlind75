#pragma once
#include "common.h"

struct node* newNode(int data)
{
	struct node* item = (struct node*) malloc(sizeof(struct node));
	item->data = data;
	item->next = NULL;
	return item;
}

void printNode(struct node* root)
{
	while (root != NULL)
	{
		printf("%d\t", root->data);
		root = root->next;
	}
	printf("\n");
}
