#include <stdio.h>
#include <stdlib.h>

/**
 * The time complexity of this exercise will be horrendous, but this is unavoidable,
 * since the exercise demands it.
 */

void print_all_subarrays_iterative(int * arr, size_t len);
void print_all_subarrays_recursive(int * arr, size_t start, size_t end, size_t len);


int main(int argc, char ** argv) {
    int arr[] = {1, 2, 3, 4};

    size_t len = sizeof(arr) / sizeof(arr[0]);

    printf("iterative approach: \n");
    print_all_subarrays_iterative(arr, len);

    printf("recursive approach:\n");
    print_all_subarrays_recursive(arr, 0, 0, len);

    return 0;
}

void print_all_subarrays_iterative(int * arr, size_t len) {

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            for (int k = i; k <= j; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

void print_all_subarrays_recursive(int * arr, size_t start, size_t end, size_t len) {

    if (end == len) {
        return;
    }

    if (start > end) {
        print_all_subarrays_recursive(arr, 0, end + 1, len);
        return;
    }

    // this part will have to be iterative
    for(size_t i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    print_all_subarrays_recursive(arr, start + 1, end, len);
    
}