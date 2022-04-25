#include "common.h"

struct node* merge2Lists_singlePointer(struct node* head, struct node* second)
{
	struct node *first = head;
	struct node *merged = head;
	while (second)
	{
		first = first->next;
		merged->next = second;
		merged = merged->next;
		second = second->next;
		merged->next = first;
		merged = merged->next;
	}
	return head;
}

struct node* merge2Lists(struct node* head, struct node* second)
{
	struct node *first = head;
	while (second)
	{
		struct node *temp1 = first->next;
		struct node *temp2 = second->next;
		first->next = second;
		second->next = temp1;
		first = temp1;
		second = temp2;
	}
	return head;
}

struct node* reOrder(struct node *head)
{
	struct node* middle = findMiddle(head); // Step 1: Find middle element using tortoise & hare
	struct node *second = reverse_LinkedList(middle->next); // Step 2: Reverse elements after middle and store it in another list
	middle->next = NULL; // set middle as last element of first list
	return merge2Lists(head, second); // Step 3: Merge the two lists
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

	head = reOrder(head);
	display(head);

	return 0;
}
