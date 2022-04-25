#include "common.h"

struct node* merge2SortedLists_ToThirdList(struct node *head, struct node* a, struct node* b)
{
	if (a == NULL)
	{
		head = b;
	}
	else if (b == NULL)
	{
		head = a;
	}
	else
	{
		struct node* tempA = a, *tempB = b;
		while (tempA != NULL && tempB != NULL)
		{
			if (tempA->data < tempB->data)
			{
				head = insert_end(head, tempA->data);
				tempA = tempA->next;
			}
			else
			{
				head = insert_end(head, tempB->data);
				tempB = tempB->next;
			}
		}
		while (tempA != NULL)
		{
			head = insert_end(head, tempA->data);
			tempA = tempA->next;
		}
		while (tempB != NULL)
		{
			head = insert_end(head, tempB->data);
			tempB = tempB->next;
		}
	}
	return head;
}

struct node* merge2SortedLists_InPlace(struct node *c, struct node* a, struct node* b)
{
	if (a == NULL)
	{
		c = b;
	}
	else if (b == NULL)
	{
		c = a;
	}
	else
	{
		if (a->data < b->data)
		{
			c = a;
			a = a->next;
		}
		else
		{
			c = b;
			b = b->next;
		}
		struct node* s = c;
		while (a != NULL && b != NULL)
		{
			if (a->data < b->data)
			{
				s->next = a;
				s = a;
				a = a->next;
			}
			else
			{
				s->next = b;
				s = b;
				b = b->next;
			}
		}
		if (a != NULL)
		{
			s->next = a;
		}
		if (b != NULL)
		{
			s->next = b;
		}
	}
	return c;
}

int main()
{
	struct node *head = NULL;
	display(head);
	
	struct node *a = NULL, *b = NULL;
	a = insert_end(a, 10);
	a = insert_end(a, 50);
	a = insert_end(a, 70);
	a = insert_end(a, 90);
	a = insert_end(a, 100);
	display(a);

	b = insert_end(b, 20);
	b = insert_end(b, 30);
	b = insert_end(b, 40);
	b = insert_end(b, 60);
	b = insert_end(b, 80);
	display(b);

	head = merge2SortedLists_ToThirdList(head, a, b);
	display(head);

	struct node *c = NULL;
	c = merge2SortedLists_InPlace(c, a, b);
	display(c);
	return 0;
}