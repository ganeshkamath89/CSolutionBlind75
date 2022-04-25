#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Interval
{
	int start;
	int end;
};

int min(int a, int b);
int max(int a, int b);
void swap(int* a, int *b);
bool doesOverlap(struct Interval a, struct Interval b);
struct Interval* sortIntervals(struct Interval* intervals, int n);