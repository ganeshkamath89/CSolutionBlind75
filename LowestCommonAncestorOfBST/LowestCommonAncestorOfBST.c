#include "common.h"

struct node* lowestCommonAncestor(struct node *root, int p, int q)
{
	if (root == NULL)
	{

		return NULL;
	}

	if (root->data == p || root->data == q)
	{
		return root;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return NULL;
	}

	struct node *left = NULL, *right = NULL;
	if (root->left)
	{
		left = lowestCommonAncestor(root->left, p, q);
	}
	if (root->right)
	{
		right = lowestCommonAncestor(root->right, p, q);
	}

	if (left != NULL && right != NULL)
	{
		return root;
	}
	return left != NULL ? left : right;
}

int main()
{
	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->data = 5;
	root->left = root->right = NULL;
	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 8);
	insert(root, 6);
	insert(root, 9);



	int LCA = lowestCommonAncestor(root, 2, 4)->data;
	printf("Lowest Common Ancestor: %d", LCA);

	return 0;
}