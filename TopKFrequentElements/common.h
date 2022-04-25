#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node {
	int no;
	int freq;
};

// Heap helpers
void swap(struct node *a, struct node *b);
void heap_push(int max_size, struct node value);
struct node heap_pop();
void show_heap();
void init(int max_size);
void fini();

// Hashmap helpers

#define HASHMAP_SIZE 20
int hashCode(int key);
struct node *search_Hash(int key);
void insert_Hash(int key, int data);
struct node* delete_Hash(struct node* item);
void display_Hash();