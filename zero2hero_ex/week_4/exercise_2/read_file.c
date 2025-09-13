#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fptr = fopen("write_digits.dat", "rb");

    int array[11];
    char w_array[11];

    fread(array, sizeof(array), 11, fptr);
    fread(w_array, sizeof(w_array), 11, fptr);

    for(int i = 0; i < sizeof(array); i++){
        printf("%d", array[i]);
    }

    for(int i = 0; i < sizeof(w_array); i++){
        printf("%d", w_array[i]);
    }

    return 0;
}