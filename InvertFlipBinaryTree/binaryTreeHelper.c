#include "common.h"

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

struct node* createBST(struct node* root, int data)
{
	if (root == NULL)
	{
		return newNode(data);
	}
	if (data < root->data)
	{
		root->left = createBST(root->left, data);
	}
	else
	{
		root->right = createBST(root->right, data);
	}
	return root;
}

void preOrder(struct node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		preOrder(p->left);
		preOrder(p->right);
	}
}