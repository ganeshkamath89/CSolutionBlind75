#pragma once
#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int value);
void display(struct node* p);
struct node* reverse_LinkedList(struct node *head);
struct node* findMiddle(struct node *head);