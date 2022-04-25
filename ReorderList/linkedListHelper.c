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

struct node* reverse_LinkedList(struct node *head)
{
	struct node *prev = NULL, *curr = head, *save;
	while (curr != NULL)
	{
		save = curr->next;
		curr->next = prev;
		prev = curr;
		curr = save;
	}
	head = prev;
	return head;
}
struct node* findMiddle(struct node *head)
{
	if (!head)
	{
		printf("No middle element as linked list is empty\n");
		return;
	}
	struct node* Tortoise = head;
	struct node* Hare = head;
	while (Hare != NULL && Hare->next != NULL)
	{
		Tortoise = Tortoise->next;
		Hare = Hare->next->next;
	}
	printf("Middle element: %d\n", Tortoise->data);
	return Tortoise;
}