#include "common.h"
struct Node* newNode(int key)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void preOrder(struct Node *root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}