#ifndef SORT_H
#define SORT_H
#include "vector.h"

void quicksort(vector * vec, int low, int high);
int partition(vector * vec, int low, int high);
void swap(int * a, int * b);

#endif