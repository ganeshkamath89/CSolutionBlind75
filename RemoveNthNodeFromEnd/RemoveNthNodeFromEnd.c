#include "common.h"

struct node* removeNthNodeFromEnd(struct node *head, int n)
{
	struct node* dummy = newNode(0);
	dummy->next = head;

	struct node *left = dummy, *right = head;
	while (n > 0 && right != NULL)
	{
		right = right->next;
		n--;
	}

	while (right != NULL)
	{
		left = left->next;
		right = right->next;
	}

	struct node* temp = left->next;
	left->next = left->next->next;
	free(temp);
	return dummy->next;
}

int main()
{
	struct node *head = NULL;
	display(head);

	struct node *a = NULL;
	a = insert_end(a, 10);
	a = insert_end(a, 50);
	a = insert_end(a, 70);
	a = insert_end(a, 90);
	a = insert_end(a, 100);
	display(a);
	
	a = removeNthNodeFromEnd(a, 2);
	display(a);
	return 0;
}