#pragma once
#include "common.h"

int heapSize = 0;
int* heap = NULL;

void swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void min_heap_push(int maxHeapSize, int value)
{
	if (heapSize >= maxHeapSize)
	{
		printf("Heap overflow\n");
		return;
	}
	heap[heapSize] = value; // Push the element to end of the heap
	int cur = heapSize;
	// percolate - up
	while (cur > 0 && heap[(cur - 1) / 2] > heap[cur])
	{
		swap(&heap[cur], &heap[(cur - 1) / 2]);
		cur = (cur - 1) / 2; // Current pointer moves to parent
	}
	heapSize += 1;
	return;
}

int min_heap_pop()
{
	if (heapSize <= 0)
	{
		printf("Heap Underflow\n");
		return -1;
	}

	int popped = heap[0]; // minvalue is at heap[0]

	// Max_heapify
	heapSize -= 1; // decrement the size of the heap
	heap[0] = heap[heapSize]; // copy last element to root
	int cur = 0; // Max element is at index 0
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
			child = (heap[L] < heap[R]) ? L : R;
		}

		if (heap[cur] > heap[child])
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

int min_heap_top()
{
	if (heapSize <= 0)
	{
		printf("Heap Underflow\n");
		return -1;
	}
	int poppedValue = heap[0];
	return poppedValue;
}

bool isEmpty()
{
	return (heapSize <= 0);
}

void Show_heap()
{
	if (heapSize > 0)
	{
		for (int i = 0; i < heapSize; i++)
		{
			printf("%d\t", heap[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Heap Underflow\n");
	}
}

void init(int max_size)
{
	heapSize = 0;
	heap = (int *)calloc(max_size, sizeof(int));
}

void fini()
{
	if (heap != NULL)
	{
		free(heap);
		heap = NULL;
	}
}
