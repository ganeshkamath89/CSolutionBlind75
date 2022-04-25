#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* next;
};

// Linked List Helpers
struct node* newNode(int data);
void printNode(struct node* root);

// Heap Helpers
void swap(int*a, int*b);
void min_heap_push(int max_size, int data);
int min_heap_pop();
int min_heap_top();
bool isEmpty();
void Show_heap();
void init(int max_size);
void fini();