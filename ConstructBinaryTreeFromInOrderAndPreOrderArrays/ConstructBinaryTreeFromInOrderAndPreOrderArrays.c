#include "common.h"

int search(char arr[], int strt, int end, char value)
{
	for (int i = strt; i <= end; i++)
		if (arr[i] == value)
			return i;
	return 0;
}
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;
	if (inStrt > inEnd)
		return NULL;

	struct node* tNode = newNode(pre[preIndex++]);	/* Pick current node from Preorder traversal using preIndex and increment preIndex */
	if (inStrt == inEnd)/* If this node has no children then return */
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
	return tNode;
}

int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	struct node* root = buildTree(in, pre, 0, len - 1);

	/* Let us test the built tree by printing Inorder traversal */
	printf("\nInorder traversal of the constructed tree is \n");
	printInorder(root);
	printf("\nPreorder traversal of the constructed tree is \n");
	printPreorder(root);
	return 0;
}