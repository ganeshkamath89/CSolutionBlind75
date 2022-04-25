#include "common.h"

// Inorder traversal is done by passing k which decrements and becomes 0 upon finding the value
// If left node finds it, that value is returned. else what ever the right node returns is returned
int kthSmallest(struct node* root, int* k)
{
	if (root == NULL)
		return 0;

	int left = kthSmallest(root->left, k);
	if (left != 0)
	{
		return left;
	}

	(*k)--;
	if (*k == 0)
	{
		return root->data;
	}
	printf("%d\t", root->data);
	int right = kthSmallest(root->right, k);
	return right;
}

int main()
{
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);

	int k = 4;
	int temp = k;

	int value = kthSmallest(root, &temp);
	printf("\n");
	printf("[%d]kth smallest: %d",k, value);

	return 0;
}