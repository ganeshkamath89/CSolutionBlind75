#pragma once
#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(char data);
struct node* insert(struct node* p, int data);