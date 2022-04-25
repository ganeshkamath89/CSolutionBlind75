#include "common.h"

struct node* mergeKSortedLists(struct node** arr, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (arr[i] != NULL)
		{
			min_heap_push(k, arr[i]->data); // Insert column 0 values for all arrays
		}
	}
	if (isEmpty())
	{
		return NULL;
	}
	struct node *dummy = newNode(0);
	struct node *last = dummy;

	while (!isEmpty())
	{
		struct node* curr = newNode(min_heap_pop());
		last->next = curr;
		last = last->next;
		for (int i = 0; i < k; i++)
		{
			if (arr[i] != NULL && (arr[i]->data == curr->data))
			{
				arr[i] = arr[i]->next;
				if (arr[i] != NULL)
				{
					min_heap_push(k, arr[i]->data);
					break;
				}
			}
		}
	}
	return dummy->next;
}

int main()
{
	int k = 3, n = 4;
	struct node** arr = (struct node**)malloc(k * sizeof(struct node*));
	for (int i = 0; i < k; i++)
	{
		arr[i] = (struct node*)malloc(n * sizeof(struct node));
	}

	arr[0] = newNode(2);
	arr[0]->next = newNode(4);
	arr[0]->next->next = newNode(6);
	arr[0]->next->next->next = newNode(8);
	printNode(arr[0]);

	arr[1] = newNode(1);
	arr[1]->next = newNode(3);
	arr[1]->next->next = newNode(5);
	arr[1]->next->next->next = newNode(7);
	printNode(arr[1]);

	arr[2] = newNode(0);
	arr[2]->next = newNode(9);
	arr[2]->next->next = newNode(10);
	arr[2]->next->next->next = newNode(11);
	printNode(arr[2]);

	init(k);
	struct node* sortedList2 = mergeKSortedLists(arr, k);
	printNode(sortedList2);
	fini();

	return 0;
}
