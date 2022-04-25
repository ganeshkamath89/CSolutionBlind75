#include "common.h"

struct node* reverse_LinkedList_Recursively(struct node *head, struct node* prev, struct node* curr)
{
	if (curr == NULL)
	{
		return head;
	}
	if (curr->next == NULL)
	{
		head = curr;
		curr->next = prev;
		return head;
	}
	head = reverse_LinkedList_Recursively(head, curr, curr->next);
	curr->next = prev;
	return head;
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

int main()
{
	struct node *head = newNode(5);
	head->next = newNode(10);
	head->next->next = newNode(15);
	head->next->next->next = newNode(20);
	head->next->next->next->next = newNode(25);
	head->next->next->next->next->next = newNode(30);
	head->next->next->next->next->next->next = newNode(35);
	head->next->next->next->next->next->next->next = newNode(40);
	display(head);

	head = reverse_LinkedList(head);
	display(head);

	struct node *prev = NULL, *curr = head;
	head = reverse_LinkedList_Recursively(head, prev, curr);
	display(head);

	return 0;
}
