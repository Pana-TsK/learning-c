#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/* vector functions & structs*/

vector * init() {
    
    vector * vec = malloc(sizeof(vector));

    vec->v = malloc(INIT_CAP * sizeof(int));

    if (!vec->v) {
        fprintf(stderr, "error creating vector: memory not allocated.\n");
        exit(1);
    }

    vec->cap = INIT_CAP;
    vec->len = 0;
}

void push(vector * vec, int num) {
    
    if (vec->len >= vec->cap) {

        vec->cap *= 2;
        int * temp_ptr = realloc(vec->v, sizeof(int) * vec->cap);

        if (!temp_ptr) {
            fprintf(stderr, "failed to allocate additional memory for our vector.\n");
            exit(1);
        }

        vec->v = temp_ptr;
    }

    vec->v[vec->len++] = num;

}

void print(vector * vec) {

    printf("[");

    for (int i = 0; i < vec->len; i++) {
        printf("%d", vec->v[i]);
        
        if (i < vec->len - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

