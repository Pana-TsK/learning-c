#include <stdio.h>
#include <stdlib.h>

#define INIT_CAP 10

typedef struct vector {
    int * data;
    size_t capacity;
    size_t length;
} vector;

typedef struct vector_iterator {
    vector * Vector;
    size_t index;
} vector_iterator;

vector * vector_init() {

    vector * v = malloc(sizeof(v));

    v->data = malloc(INIT_CAP * sizeof(int));
    v->capacity = INIT_CAP;
    v->length = 0;

    return v;
}

void vector_push(vector * v, int num) {

    if (v->length >= v->capacity) {
        // allocate a bigger array for the
        v->capacity *=2;
        int * temp_ptr = realloc(v->data, v->capacity * sizeof(int));

        if (!temp_ptr) {
            fprintf(stderr, "error while attempting to allocate more space to the array");
            return;
        }
        v->data = temp_ptr;
    }

    v->data[v->length++] = num; 
}

int vector_pop(vector * v) {
    // check if there is anything to pop
    if (!v->length) {
        fprintf(stderr, "Array is empty.\n");
        return -1;
    }

    int num = v->data[--v->length];
    v->data[v->length] = 0;

    return num;
}

void vector_resize(vector * v, int new_length) {
    if (new_length < v->length) {
        printf("warning: new length is smaller than previous length. Some data will be lost.\n");
    }

    v->capacity = v->length;
    int * tmp_ptr = realloc(v->data, v->capacity * sizeof(int));
    v->length = new_length;
}

void print(vector * v) {

    printf("[");

    for (int i =0; i < v->length; i++) {
        printf("%d", v->data[i]);

        if (i < v->length-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

vector_iterator vector_iter(vector * v) {
    vector_iterator v_iter = {v, 0};

    return v_iter;
}

int vector_has_next(vector_iterator * it) {
    return it->index < it->Vector->length;
}

// Return current element and advance
int vector_next(vector_iterator *it) {
    if (!vector_has_next(it)) {
        fprintf(stderr, "Iterator out of bounds\n");
        exit(1);
    }
    return it->Vector->data[it->index++];
}


int main() {
    vector * v = vector_init();

    vector_push(v, 1);
    vector_push(v, 2);
    vector_push(v, 4);
    vector_push(v, 5);

    print(v);

    int i = vector_pop(v);
    printf("popped number %d\n", i);
    print(v);

    vector_resize(v, 9);
    print(v);

    vector_resize(v, 6);
    print(v);

    vector_iterator it = vector_iter(v);
    while (vector_has_next(&it)) {
        int val = vector_next(&it);
        printf("%d\n", val);
}

}