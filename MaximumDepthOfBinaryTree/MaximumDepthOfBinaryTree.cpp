#include "common.h"

int MaximumDepth(struct node* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = MaximumDepth(root->left);
	int rightDepth = MaximumDepth(root->right);

	return 1 + max(leftDepth, rightDepth);
}

int main()
{
	int arr[] = { 2,1,5,4,3,6 };
	/*
		  2
		 / \
		1   5
		   / \
		  4   6
		 /
		3
	*/
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node* bst = NULL;
	for (int i = 0; i < len; i++)
	{
		bst = createBST(bst, arr[i]);
	}
	int Result = MaximumDepth(bst);
	printf("Maximum depth: %d", Result);
	return 0;
}