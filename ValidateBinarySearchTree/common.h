#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);