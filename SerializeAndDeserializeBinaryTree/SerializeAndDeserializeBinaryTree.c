#include "common.h"

void serialize(struct Node* root, FILE* fp)
{
	if (root == NULL)
	{
		fprintf(fp, "%d ", MARKER);
		return;
	}
	fprintf(fp, "%d ", root->data);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

struct Node* deSerialize(struct Node *root, FILE *fp)
{
	int val;
	if (!fscanf(fp, "%d ", &val) || val == MARKER)
		return NULL;

	root = newNode(val);// Else create node with this item and recur for children
	root->left = deSerialize(root->left, fp);
	root->right = deSerialize(root->right, fp);
	return root;
}

int main()
{
	// Let us construct a tree shown in the above figure
	struct Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	preOrder(root);
	// Let us open a file and serialize the tree into the file
	FILE *fp = fopen("tree.txt", "w");
	if (fp == NULL)
	{
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);
	printf("\n");

	// Let us deserialize the stored tree into root1
	struct Node *root1 = NULL;
	fp = fopen("tree.txt", "r");
	root1 = deSerialize(root1, fp);

	printf("\nPreOrder Traversal of the tree constructed from file:\n");
	preOrder(root1);

	return 0;
}