#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

int maxValue(int a, int b);
int height(struct node* root);
struct node* newNode(int data);
