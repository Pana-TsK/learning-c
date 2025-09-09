#include <stdio.h>
#include <stdlib.h>
#include "binmain.h"
#include "quicksort.h"
#include "binsearch.h"

int main(int argc, char * argv[]) {

    array * v = malloc(sizeof(array));
    if (!v) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    v->len = argc - 1;
    v->array = malloc(v->len * sizeof(int));
    if (!v->array) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        v->array[i - 1] = atoi(argv[i]);
    }
    printf("initial array:\n");
    print_array(v);

    quicksort(v, 0, v->len - 1);
    printf("Quick-sorted array:\n");
    print_array(v);

    int a = binarysearch(v, v->len, 2);
    printf("found digit 2 at index %d\n", a);

    int b = binarysearch(v, v->len, 7);
    printf("found digit 7 at index %d\n", b);

    int c = binarysearch(v, v->len, 12);

    free(v->array);
    free(v);
    return 0;
}

void print_array(array * v) {
    printf("[");

    for (int i = 0; i < v->len; i++) {
        printf("%d", v->array[i]);

        if (i < v->len - 1) {
            printf(", ");
        }
    }

    printf("]\n");
} 