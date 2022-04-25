#include "common.h"

struct node* hashArray[HASHMAP_SIZE];
struct node* dummyItem;
struct node* item;

int hashCode(int key) {
	return key % HASHMAP_SIZE;
}

struct node *search_Hash(int key) {
	//get the hash 
	int hashIndex = hashCode(key);
	while (hashArray[hashIndex] != NULL) {//move in array until an empty 
		if (hashArray[hashIndex]->no == key)
			return hashArray[hashIndex];
		++hashIndex;
		hashIndex %= HASHMAP_SIZE;//wrap around the table
	}
	return NULL;
}

void insert_Hash(int key, int data) {
	struct node *item = (struct node*) malloc(sizeof(struct node));
	item->freq = data;
	item->no = key;
	int hashIndex = hashCode(key);
	hashArray[hashIndex] = item;
}

struct node* delete_Hash(struct node* item) {
	int key = item->no;
	int hashIndex = hashCode(key);
	while (hashArray[hashIndex] != NULL) {//move in array until an empty
		if (hashArray[hashIndex]->no == key) {
			struct node* temp = hashArray[hashIndex];

			//assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		++hashIndex;
		hashIndex %= HASHMAP_SIZE;//wrap around the table
	}
	return NULL;
}

void display_Hash() {
	int i = 0;
	for (i = 0; i < HASHMAP_SIZE; i++) {
		if (hashArray[i] != NULL)
			printf("{N:%d,F:%d}\t", hashArray[i]->no, hashArray[i]->freq);
	}
	printf("\n");
}
