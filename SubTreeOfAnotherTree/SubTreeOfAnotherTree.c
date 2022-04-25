#include "common.h"
bool isSame(struct node* a, struct node*b)
{
	if (a == NULL && b == NULL)
		return true;
	else if ((a == NULL && b != NULL) || (a != NULL && b == NULL) || (a->data != b->data))
		return false;

	bool leftCheck = isSame(a->left, b->left);
	bool rightCheck = isSame(a->right, b->right);
	return leftCheck && rightCheck;
}

bool isSubTree(struct node* root, struct node* subTree)
{
	if (root == NULL)
	{
		return false;
	}
	else if (isSame(root, subTree) == true)
	{
		printf("Testing node: %d\n", root->data);
		return true;
	}
	else
	{
		return (isSubTree(root->left, subTree) || isSubTree(root->right, subTree));
	}
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
	struct node* a = NULL, *b = NULL, *c = NULL;
	for (int i = 0; i < len; i++)
	{
		a = createBST(a, arr[i]);
	}
	for (int i = 0; i < len; i++)
	{
		b = createBST(b, arr[i]);
	}
	//b = createBST(b, 7); // To test if it prints failure

	printf("The two binary trees are %s same\n", isSame(a, b) ? "indeed" : "not");

	int arr2[] = { 5,4,3,6 };
	/*
			5
		   / \
		  4   6
		 /
		3
	*/
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < len2; i++)
	{
		c = createBST(c, arr2[i]);
	}
	printf("The third binary tree %s subtree of the previous tree", isSubTree(a, c) ? "is the" : "is not the");

	return 0;
}
