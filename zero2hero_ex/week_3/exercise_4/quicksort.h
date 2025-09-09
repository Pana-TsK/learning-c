#ifndef QUICK_H
#define QUICK_H

#include "binmain.h"

int partition(array * v, int low, int high);
void quicksort(array *v, int low, int high);
void swap(int * a, int * b);

#endif