#include "common.h"
struct Trienode *getNode(int index)
{
	struct Trienode* newnode = (struct Trienode *)malloc(sizeof(struct Trienode));
	newnode->val = 'a' + index;
	newnode->count = newnode->endsHere = 0;
	for (int i = 0; i < 26; ++i)
		newnode->child[i] = NULL;
	return newnode;
}