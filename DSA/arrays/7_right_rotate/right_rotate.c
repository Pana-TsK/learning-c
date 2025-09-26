#include <stdio.h>
#include <stdlib.h>

void stepwise_right_rotation(int * arr, int d, int len);
void temparr_right_rotation(int * arr, int d, int len);


void print_array(int * arr, int len);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    stepwise_right_rotation(arr, 2, len);
    print_array(arr, len);

    return 0;
}

void stepwise_right_rotation(int * arr, int d, int len) {

    for (int i = 0; i < d; i++) {

        int last = arr[len - 1];
        for (int k = len - 1; k > 0; k--) {
            arr[k] = arr[k - 1];
        }
        arr[0] = last;
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