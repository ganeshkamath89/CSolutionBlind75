#include "common.h"

struct node* newNode(char data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
}

void printPreorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%c ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}
