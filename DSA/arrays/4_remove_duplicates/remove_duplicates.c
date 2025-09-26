#include <stdio.h>
#include <stdlib.h>

// since the array is sorted, this should not be too challenging
int * remove_duplicates(int * arr, int old_length, int *new_length);
void print_array(int * arr, int len);

int main(int argc, int * argv) {
    int array_1[] = {1, 3, 3, 3, 3, 4, 5, 5, 6, 7};
    int array_2[] = {1, 3, 4, 5, 6, 7};

    int len_1 = sizeof(array_1) / sizeof(array_1[0]);
    int len_2 = sizeof(array_2) / sizeof(array_2[0]);

    int new_len_1, new_len_2;

    int * arr_1 = remove_duplicates(array_1, len_1, &new_len_1);
    print_array(arr_1, new_len_1);

    int * arr_2 = remove_duplicates(array_2, len_2, &new_len_2);
    print_array(arr_2, new_len_2);
}

int * remove_duplicates(int * arr, int old_length, int *new_length) {

    int j = 0; // new pointer to the array
    int * new_array = malloc(sizeof(int)* old_length);

    new_array[j++] = arr[0]; 

    for (int i = 1; i < old_length; i++) {
        if (arr[i] != arr[i-1]) {
            new_array[j++] = arr[i];
        }
    }

    * new_length = j;
    return new_array;
}

void print_array(int * arr, int len){

    printf("[");

    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);

        if (i < len - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}
