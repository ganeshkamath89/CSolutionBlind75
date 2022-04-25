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
	else if (data > root->data)
	{
		root->right = createBST(root->right, data);
	}
	else
	{
		// skip duplicate elements
	}
	return root;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
