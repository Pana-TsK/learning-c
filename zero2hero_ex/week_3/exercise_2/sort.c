#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "sort.h"



// not yet implemented.
void quicksort(vector   * vec, int low, int high) {
    if(low < high) {

        int pi = partition(vec, low, high);

        // perform the partition on the left side
        quicksort(vec, low, pi-1);
        
        // perform the partition on the right side
        quicksort(vec, pi + 1, high);

    }
}

int partition(vector * v, int low, int high) {
    int * arr = v->v;

    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high ; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // swap the location of the array with the last unmoved element to where the pivot is
    swap(&arr[i+1], &arr[high]);

    // return point of partition
    return (i + 1);
}

void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}