#include "common.h"

int heapSize = 0;
struct node* heap;

void swap(struct node *a, struct node *b)
{
	struct node temp = *a;
	*a = *b;
	*b = temp;
}

void heap_push(int max_size, struct node value)
{
	if (heapSize >= max_size)
	{
		printf("Heap overflow\n");
		return;
	}
	heap[heapSize] = value; // Push the element to end of the heap
	int cur = heapSize;
	// percolate - up
	while (cur > 0 && heap[(cur - 1) / 2].freq < heap[cur].freq)
	{
		swap(&heap[cur], &heap[(cur - 1) / 2]);
		cur = (cur - 1) / 2; // Current pointer moves to parent
	}
	heapSize += 1;

	return;
}

struct node heap_pop()
{
	if (heapSize <= 0)
	{
		printf("Heap Underflow\n");
		struct node emptyNode;
		emptyNode.freq = 0;
		emptyNode.no = 0;
		return emptyNode;
	}

	int cur = 0; // Max element is at index 0
	struct node popped = heap[0]; // maxvalue is at heap[0]
	heap[0] = heap[heapSize - 1]; // copy last element to root
	heapSize -= 1; // decrement the size of the heap

	// Max_heapify
	while ((2 * cur + 1) < heapSize) // while we don't reach the leaf node
	{
		int child = 0;
		int L = 2 * cur + 1, R = 2 * cur + 2; // Left and Right child indices
		if (L == heapSize) // if we only have left child
		{
			child = L;
		}
		else
		{
			child = ((heap[L].freq) > (heap[R].freq)) ? L : R;
		}

		if (heap[cur].freq < heap[child].freq)
		{
			swap(&heap[cur], &heap[child]);
			cur = child;
		}
		else
		{
			break;
		}
	}
	return popped;
}

void show_heap()
{
	if (heapSize > 0)
	{
		for (int i = 0; i < heapSize; i++)
		{
			printf("{N:%d, F:%d}\t", heap[i].no, heap[i].freq);
		}
	}
	else
	{
		printf("Heap is empty");
	}
	printf("\n");
	return;
}

void init(int max_size)
{
	heapSize = 0;
	heap = (struct node*)calloc(max_size, sizeof(struct node));
}

void fini()
{
	free(heap);
}