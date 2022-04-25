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
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
