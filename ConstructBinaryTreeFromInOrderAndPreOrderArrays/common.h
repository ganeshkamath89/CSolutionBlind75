#pragma once
#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node *left, *right;
};

struct node* newNode(char data);
void printInorder(struct node* node);
void printPreorder(struct node* node);