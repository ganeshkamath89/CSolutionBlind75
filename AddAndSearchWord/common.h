#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

struct Trienode
{
	char val;
	int endsHere; // word End
	struct Trienode* child[26];
};

struct Trienode *getNode(int index);
void init();