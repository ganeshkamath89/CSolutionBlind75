#include "common.h"
void addNumberFromDataStream(int num) {
	if (getMaxHeapSize() == 0)    //num is the 1st element in stream
	{
		max_heap_push(num);
	}
	else if (getMaxHeapSize() == getMinHeapSize())   //Push one element in maxheap for sure
	{
		if (num < min_heap_top())   //num can be pushed to maxheap (1st half) to maintain order
		{
			max_heap_push(num);
		}
		else    //Push root of minheap to maxheap (Push num to 2nd half)
		{
			int temp = min_heap_pop();   //Save root of minheap
			min_heap_push(num);  //Push num in minheap
			max_heap_push(temp); //Push the previous saved root of minheap in the maxheap
		}
	}
	else
	{
		if (num >= max_heap_top()) //Push num to 2nd half
		{
			min_heap_push(num);
		}
		else						 //Push root of maxheap to minheap
		{
			int temp = max_heap_pop();   //Save root of maxheap
			max_heap_push(num);  //Push num to maxheap
			min_heap_push(temp);//Push previous saved root of maxheap to minheap
		}
	}
}

double findMedian() {
	if (getMaxHeapSize() > getMinHeapSize())  //Return top of maxheap for odd no of elements
		return (double)max_heap_top();
	else    //Else return avg of top of maxheap and minheap
		return ((double)(max_heap_top()) + (double)(min_heap_top())) / 2;
}

void initializeMaxMinHeaps(int max)
{
	initMaxHeap(max);
	initMinHeap(max);
}

void FreeMaxMinHeaps()
{
	finiMinHeap();
	finiMaxHeap();
}

int main()
{
	int arr[] = { 5,3,4,2,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	initializeMaxMinHeaps(n);
	for (int i = 0; i < n; i++)
	{
		addNumberFromDataStream(arr[i]);
		double median = findMedian();
		printf("median of %d numbers %.2lf\n", i + 1, median);
	}
	FreeMaxMinHeaps();
	return 0;
}