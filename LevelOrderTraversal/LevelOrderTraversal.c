#include "common.h"

void printCurrentLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

void printLevelOrder(struct node* root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printCurrentLevel(root, i);
	}
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);
	printf("\n");

	int arr[] = { 4,2,1,3,6,5,7 };
	/*
			4
		   / \
		  2   6
		 / | | \
		1  3 5  7
	*/
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node* bst = NULL;
	for (int i = 0; i < len; i++)
	{
		bst = createBST(bst, arr[i]);
	}
	printLevelOrder(bst);
	return 0;
}