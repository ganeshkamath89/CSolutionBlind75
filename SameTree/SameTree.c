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

int main()
{
	int arr[] = { 2,1,5,4,3,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node* a = NULL, *b = NULL;
	for (int i = 0; i < len; i++)
	{
		a = createBST(a, arr[i]);
	}
	for (int i = 0; i < len; i++)
	{
		b = createBST(b, arr[i]);
	}
	//b = createBST(b, 7); // To test if it prints failure

	printf("The two binary trees are %s same", isSame(a, b) ? "indeed" : "not");
	return 0;
}