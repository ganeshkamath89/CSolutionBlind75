#include "common.h"
void invert(struct node* root)
{
	if (root == NULL)
		return;

	invert(root->left);
	invert(root->right);

	struct node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int main()
{
	int arr[] = { 2,1,5,4,3,6 };
	/*
	Tree
		  2
		 / \
		1   5
		   / \
		  4   6
		 /
		3

	Inverted Tree
			2
		   / \
		  5   1
		 / \
		6   4
			 \
			  3
	*/
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node* a = NULL;
	for (int i = 0; i < len; i++)
	{
		a = createBST(a, arr[i]);
	}
	printf("\nBefore invert:\n");
	preOrder(a);
	invert(a);

	printf("\nAfter invert:\n");
	preOrder(a);
	return 0;
}