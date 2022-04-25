#include "common.h"
// common for minHeap & maxHeap
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*min heap code start*/
int minHeapMaxSize = INT_MAX;
int minHeapSize = 0;
int* minHeap;

void min_heap_push(int value)
{
	if (minHeapSize >= minHeapMaxSize)
	{
		printf("min heap overflow\n");
		return;
	}
	minHeap[minHeapSize] = value; // Push the element to end of the heap
	int cur = minHeapSize;
	// percolate - up
	while (cur > 0 && minHeap[(cur - 1) / 2] > minHeap[cur])
	{
		swap(&minHeap[cur], &minHeap[(cur - 1) / 2]);
		cur = (cur - 1) / 2; // Current pointer moves to parent
	}
	minHeapSize += 1;

	return;
}

int min_heap_pop()
{
	if (minHeapSize <= 0)
	{
		printf("min heap underflow\n");
		return -1;
	}

	int popped = minHeap[0]; // minvalue is at heap[0]

	// Max_heapify
	minHeapSize -= 1; // decrement the size of the heap
	minHeap[0] = minHeap[minHeapSize]; // copy last element to root
	int cur = 0; // Max element is at index 0
	while ((2 * cur + 1) < minHeapSize) // while we don't reach the leaf node
	{
		int child = 0;
		int L = 2 * cur + 1, R = 2 * cur + 2; // Left and Right child indices
		if (L == minHeapSize) // if we only have left child
		{
			child = L;
		}
		else
		{
			child = (minHeap[L] < minHeap[R]) ? L : R;
		}

		if (minHeap[cur] > minHeap[child])
		{
			swap(&minHeap[cur], &minHeap[child]);
			cur = child;
		}
		else
		{
			break;
		}
	}
	return popped;
}

int min_heap_top()
{
	if (minHeapSize <= 0)
	{
		printf("min heap underflow\n");
		return -1;
	}

	return minHeap[0];
}

void show_minHeap()
{
	if (minHeapSize > 0)
	{
		for (int i = 0; i < minHeapSize; i++)
		{
			printf("%d\t", minHeap[i]);
		}
	}
	else
	{
		printf("min heap is empty\n");
	}
	printf("\n");
}

void initMinHeap(int maxSize)
{
	minHeapSize = 0;
	minHeapMaxSize = maxSize;
	minHeap = (int*)calloc(maxSize, sizeof(int));
}

void finiMinHeap()
{
	if (minHeap != NULL)
	{
		free(minHeap);
		minHeap = NULL;
	}
}

int getMinHeapSize()
{
	return minHeapSize;
}
/*min heap code end*/


// max heap code start
int maxHeapMaxSize = INT_MAX;
int maxHeapSize = 0;
int* maxHeap;

void max_heap_push(int value)
{
	if (maxHeapSize >= maxHeapMaxSize)
	{
		printf("max heap overflow\n");
		return;
	}
	maxHeap[maxHeapSize] = value; // Push the element to end of the heap
	int cur = maxHeapSize;
	// percolate - up
	while (cur > 0 && maxHeap[(cur - 1) / 2] < maxHeap[cur])
	{
		swap(&maxHeap[cur], &maxHeap[(cur - 1) / 2]);
		cur = (cur - 1) / 2; // Current pointer moves to parent
	}
	maxHeapSize += 1;

	return;
}

int max_heap_pop()
{
	if (maxHeapSize <= 0)
	{
		printf("max heap Underflow\n");
		return -1;
	}

	int cur = 0; // Max element is at index 0
	int popped = maxHeap[0]; // maxvalue is at heap[0]
	maxHeap[0] = maxHeap[maxHeapSize - 1]; // copy last element to root
	maxHeapSize -= 1; // decrement the size of the heap

	// Max_heapify
	while ((2 * cur + 1) < maxHeapSize) // while we don't reach the leaf node
	{
		int child = 0;
		int L = 2 * cur + 1, R = 2 * cur + 2; // Left and Right child indices
		if (L == maxHeapSize) // if we only have left child
		{
			child = L;
		}
		else
		{
			child = ((maxHeap[L]) > (maxHeap[R])) ? L : R;
		}

		if (maxHeap[cur] < maxHeap[child])
		{
			swap(&maxHeap[cur], &maxHeap[child]);
			cur = child;
		}
		else
		{
			break;
		}
	}
	return popped;
}

int max_heap_top()
{
	if (maxHeapSize <= 0)
	{
		printf("max heap Underflow\n");
		return -1;
	}
	return maxHeap[0];
}

void show_maxHeap()
{
	if (maxHeapSize > 0)
	{
		for (int i = 0; i < maxHeapSize; i++)
		{
			printf("%d\t", maxHeap[i]);
		}
	}
	else
	{
		printf("max heap is empty\n");
	}
	printf("\n");
}

void initMaxHeap(int max_size)
{
	maxHeapSize = 0;
	maxHeapMaxSize = max_size;
	maxHeap = (int*)calloc(max_size, sizeof(int));
}

void finiMaxHeap()
{
	if (maxHeap != NULL)
	{
		free(maxHeap);
		maxHeap = NULL;
	}
}

int getMaxHeapSize()
{
	return maxHeapSize;
}