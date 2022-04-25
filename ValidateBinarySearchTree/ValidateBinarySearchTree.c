#include "common.h"

bool isBSTNodeValid(struct node* root, int min, int max)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->data < min || root->data > max)
	{
		return false;
	}

	return isBSTNodeValid(root->left, min, root->data - 1)
		&& isBSTNodeValid(root->right, root->data + 1, max);
}

bool isBST(struct node* root)
{
	return isBSTNodeValid(root, INT_MIN, INT_MAX);
}

int main()
{
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);

	if (isBST(root))
		printf("Is BST");
	else
		printf("Not a BST");

	return 0;
}