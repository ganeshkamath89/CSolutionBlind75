#include "common.h"

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

	struct node *a = NULL;
	a = insert_end(a, 10);
	a = insert_end(a, 50);
	a = insert_end(a, 70);
	a = insert_end(a, 90);
	a = insert_end(a, 100);
	display(a);
	
	struct node *b = NULL;
	b = insert_end(b, 20);
	b = insert_end(b, 30);
	b = insert_end(b, 40);
	b = insert_end(b, 60);
	b = insert_end(b, 80);
	display(b);

	struct node *c = NULL;
	c = merge2SortedLists_InPlace(c, a, b);
	display(c);

	struct node *d = NULL;
	d = insert_end(d, 0);
	d = insert_end(d, 5);
	d = insert_end(d, 120);
	d = insert_end(d, 130);
	d = insert_end(d, 140);
	d = insert_end(d, 160);
	d = insert_end(d, 180);
	display(d);

	c = merge2SortedLists_InPlace(c, c, d);
	display(c);
	return 0;
}