#include "common.h"

struct node* newNode(int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}

struct node* insert_beg(struct node* head, int value)
{
	struct node* temp = newNode(value);
	temp->next = head;
	head = temp;
	return head;
}

struct node* insert_end(struct node* head, int value)
{
	struct node* temp = newNode(value);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct node* tempHead = head;
		while (tempHead->next != NULL)
		{
			tempHead = tempHead->next;
		}
		tempHead->next = temp;
	}
	return head;
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