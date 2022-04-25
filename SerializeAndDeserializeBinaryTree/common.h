#pragma once
#include <stdio.h>
#include <malloc.h>
#define MARKER -1

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int key);
void preOrder(struct Node *root);