#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_sorted_iterative(int * arr, int len) {

    bool sorted = true;

    for (int i = 1; i < len; i++) {
        if(arr[i] < arr[i-1]){
            sorted = false;
            return sorted;
        }
    }

    return sorted;
}


bool check_sorted_recursive(int * arr, int n, int len) {

    if (n == len)
        return true;
    
    bool sorted = (arr[n] > arr[n - 1] && check_sorted_recursive(arr, n + 1, len));
    
    return sorted;
}

int main(int * argc, char ** argv) {

    int sorted_array[]      = {1, 20, 30, 40, 100, 150};
    int unsorted_array[]    = {1, 20, 40, 25, 100, 80};

    int sorted_length   = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int unsorted_length = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    bool sorted_first   = check_sorted_iterative(sorted_array, sorted_length);
    bool unsorted_first = check_sorted_iterative(unsorted_array, unsorted_length);

    printf("sorted array:    %d\n", sorted_first);
    printf("unsorted array:  %d\n", unsorted_first);

    bool sorted_sec   = check_sorted_recursive(sorted_array, 1, sorted_length);
    bool unsorted_sec = check_sorted_recursive(unsorted_array, 1, unsorted_length);
    
    printf("sorted array:    %d\n", sorted_sec);
    printf("unsorted array:  %d\n", unsorted_sec);

    return 0;
}