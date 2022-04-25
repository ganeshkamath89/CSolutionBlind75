#pragma once
#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node* next;
};

struct node* newNode(int value);
struct node* insert_beg(struct node* head, int value);
struct node* insert_end(struct node* head, int value);
void display(struct node* p);