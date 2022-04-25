#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <limits.h>

void swap(int *a, int *b);

// min heap code start
void min_heap_push(int value);
int min_heap_pop();
int min_heap_top();
void show_minHeap();
void initMinHeap(int maxSize);
void finiMinHeap();
int getMinHeapSize();

// max heap code start
void max_heap_push(int value);
int max_heap_pop();
int max_heap_top();
void show_maxHeap();
void initMaxHeap(int max_size);
void finiMaxHeap();
int getMaxHeapSize();