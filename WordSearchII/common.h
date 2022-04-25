#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAXWORDLEN 64

struct Trienode
{
	char val;
	int count;
	int endsHere; // word End
	struct Trienode* child[26];
	char* word;
};

struct Trienode *getNode(int index);
void init();