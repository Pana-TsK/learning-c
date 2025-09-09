#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "binmain.h"

void quicksort(array * v, int low, int high) {

    if (low < high) {
        // initial partition
        int index = partition(v, low, high);
        
        // repeat the partition on the left & right side
        quicksort(v, low, index - 1);
        quicksort(v, index + 1, high);
    }

}

int partition(array * v, int low, int high) {

    int pivot = v->array[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {
        if (v->array[j] <= pivot) {
            i++;
            swap(&v->array[j], &v->array[i]);
        }
    }
    // swap out the pivot to after the ordered positions
    swap(&v->array[i + 1], &v->array[high]);

    return i + 1;
}

void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}