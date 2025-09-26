#include <stdio.h>
#include <stdlib.h>

int * find_leaders(int * arr, int len, int * ressize) {
    // if we run through the array in a straight way, we will have to iterate over the array
    // n times. If we do it in reverse, we can just append the value if it is the biggest
    // yet seen
    int * leaders = (int *)malloc(len * sizeof(int));

    int biggest = 0;
    * ressize = 0;


    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] > biggest) {
            leaders[(* ressize)++] = arr[i];
            biggest = arr[i];
        }
    }


    // reverse array
    for (int i = 0; i < (* ressize / 2); i++){
        int temp = leaders[i];
        leaders[i] = leaders[(* ressize) - i - 1];
        leaders[(* ressize) - i - 1] = temp;
    }

    return leaders;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};

    int leaders_size;
    int * leaders = find_leaders(arr, 6, & leaders_size);

    printf("leaders: [");
    for (int i = 0; i < leaders_size; i++) {
        printf("%d", leaders[i]);
        if (i < leaders_size - 1) printf(", ");
    }
    printf("]\n");

}