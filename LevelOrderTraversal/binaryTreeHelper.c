#include "common.h"
int maxValue(int a, int b)
{
	return a > b ? a : b;
}

int height(struct node* root)
{
	if (root == NULL)
		return 0;

	int lheight = height(root->left);
	int rheight = height(root->right);
	return 1 + max(lheight, rheight);
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
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