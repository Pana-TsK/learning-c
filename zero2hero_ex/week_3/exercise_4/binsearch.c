#include <stdio.h>
#include <stdlib.h>
#include "binsearch.h"
#include "binmain.h"

int binarysearch(array * v, int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // case 1: the middle is x
        if(v->array[mid] == x) {
            return mid;
        }

        // case 2: x is smaller than middle
        if (v->array[mid] < x) {
            low = mid + 1;
        } 
        // case 3: x is bigger than middle
        else {
            high = mid - 1;
        }
    }

    // if by now not found, number is not present
    printf("number %d is not present in the array.\n", x);
    return -1;
}