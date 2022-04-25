#include "common.h"

int* topKFrequent(int* nums, int n, int k) {
	//STEP-1: Store frequency of all elements in Hash map
	int uniqueItemCount = 0;
	for (int i = 0; i < n; i++)
	{
		struct node* ret = search_Hash(nums[i]);
		if (ret == NULL)
		{
			ret = (struct node*)malloc(sizeof(struct node));
			ret->no = nums[i];
			ret->freq = 0;
			uniqueItemCount++;
		}
		insert_Hash(ret->no, ret->freq + 1);
	}

	display_Hash();

	//STEP-2: Now build a heap
	init(uniqueItemCount);
	for (int i = 0; i < HASHMAP_SIZE; i++)
	{
		struct node* ret = search_Hash(i);
		if (ret != NULL)
		{
			heap_push(uniqueItemCount, *ret);
		}
	}

	int* ans = (int*)calloc(k, sizeof(int));    //Stores top-K elements
	int index = 0;
	//STEP-3: Pop top-k elemnts and store the numbers in ans vector
	while (k--)
	{
		struct node temp = heap_pop();
		ans[index++] = temp.no;
	}
	return ans;
}

int main()
{
	int nums[] = { 1,2,3,2,1,1,3,3,3 };
	int n = sizeof(nums) / sizeof(nums[0]);
	int k = 2;
	int* result = topKFrequent(nums, n, k);
	printf("Top %d numbers are:\t", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d\t", result[i]);
	}
	printf("\n");

	free(result);
	return 0;
	return 0;
}
