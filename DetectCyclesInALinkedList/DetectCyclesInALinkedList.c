#include "common.h"

struct node* findJunctionValue(struct node *head)
{
	if (!head)
	{
		printf("No middle element as linked list is empty\n");
		return NULL;
	}
	struct node* Tortoise = head;
	struct node* Hare = head;
	while (Hare != NULL && Hare->next != NULL)
	{
		Tortoise = Tortoise->next;
		Hare = Hare->next;
		if (Hare)
			Hare = Hare->next;

		// if they become equal, we can then find the junction
		if (Tortoise == Hare)
		{
			Tortoise = head;
			while (Tortoise != Hare)
			{
				Tortoise = Tortoise->next;
				Hare = Hare->next;
			}
			printf("Junction Value: %d\n", Tortoise->data);
			return Tortoise;
		}
	}
	return NULL; // No loops
}

void printCycle(struct node *head)
{
	struct node* slowPtr = findJunctionValue(head);
	struct node* temp = slowPtr;
	do
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	} while (temp != slowPtr);
	printf("\n");
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
	head->next->next->next->next->next->next->next = head->next->next;

	struct node *start = findJunctionValue(head);
	if (start == NULL)
	{
		printf("No cycles exist in the linked list");
	}
	else
	{
		printf("Cycle starts at node %d\n", start->data);
		printf("Cycle elements are: \n");
		printCycle(start);
	}
	return 0;
}
