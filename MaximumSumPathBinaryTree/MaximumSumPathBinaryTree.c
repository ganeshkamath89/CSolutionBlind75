#include "common.h"
int MaximumPathSum(struct node* root, int* result)
{
	if (root == NULL)
		return 0;

	int left = MaximumPathSum(root->left, result);
	int right = MaximumPathSum(root->right, result);

	int maxSumInPath = max(
		max(left, right) + root->data,
		root->data
	);

	int maxSumWithCurrentNodeAsRoot = max(maxSumInPath, left + right + root->data);
	*result = max(maxSumWithCurrentNodeAsRoot, *result);
	printf("[%d] ms: %d, m21: %d, result: %d\n", root->data, maxSumInPath, maxSumWithCurrentNodeAsRoot, *result);
	return maxSumInPath;
}

int main()
{
	int arr[] = { 4,2,1,3,6,5,7 };
	/*
			4
		   / \
		  2   6
		 / | | \
		1  3 5  7

		sum 3 + 2 + 4 + 6 + 7 = 22	
	*/
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node* bst = NULL;
	for (int i = 0; i < len; i++)
	{
		bst = createBST(bst, arr[i]);
	}
	int maximumSum = 0;
	MaximumPathSum(bst, &maximumSum);
	printf("Maximum sum: %d", maximumSum);
	return 0;
}
