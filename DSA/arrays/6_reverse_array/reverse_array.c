#include <stdio.h>
#include <stdlib.h>

void reverse_array(int * arr, int len);
void print_array(int * arr, int len);

int main(int argc, int ** argv) {
    int arr[] = {1, 2, 3, 4, 5};

    int len = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, len);
    print_array(arr, len);
}

void reverse_array(int * arr, int len) {

    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
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
