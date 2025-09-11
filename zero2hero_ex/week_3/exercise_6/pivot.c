#include <stdio.h>
#include <stdlib.h>

void quicksort(int * array, int low, int high);
int partition(int * array, int low, int high);
int median_of_three(int * array, int low, int high);
void swap(int *a, int *b);

int main(int argc, char * argv[]) {

    int length = argc - 1;

    int * array = malloc(length * sizeof(int));
    if (!array) {
        perror("Error assigning array space.\n");
    }

    // populate the array
    for(int i = 0 ; i < length ; i++) {
        array[i] = atoi(argv[i+1]);
    }

    quicksort(array, 0, length-1);
    
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    return 0;
}

void quicksort(int * array, int low, int high) {
    if (low < high){
        int pi = partition(array, low, high);

        // call on left and right side of pivot
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

int partition(int * array, int low, int high) {
    int pivot_index = median_of_three(array, low, high);
    int pivot = array[pivot_index];

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i], &array[pivot_index]);

    return i + 1;
}

int median_of_three(int * array, int low, int high){
    int mid = (high + low) / 2;

    if (array[low] > array[mid]) swap(&array[low], &array[mid]);
    if (array[low] > array[high]) swap(&array[low], &array[mid]);
    if (array[mid] > array[high]) swap(&array[mid], &array[high]);

    return mid;
}


void swap(int *a, int *b) {
    int temp = * a;
    * a = * b,
    * b = temp;
}