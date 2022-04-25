#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);
struct node* createBST(struct node* root, int data);
int max(int a, int b);