#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAP 5

typedef struct {
    int * data;
    int size;
    int capacity;
} Vector;

Vector * Vector_create() {
    Vector * v = malloc(sizeof(Vector));
    v->capacity = INITIAL_CAP;
    v->data = malloc(v->capacity * sizeof(int));
    v->size = 0;

return v;
}

void Vector_push(Vector * vector, int digit) {
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;

        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
    }

    (vector->data)[vector->size++] = digit;
}

int Vector_pop(Vector * vector) {
    if (vector->size == 0) {
        return -1;
    }

    return vector->data[--vector->size];

}

void Vector_resize(Vector * vector, int new_length){
    vector->capacity = new_length;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
    vector->size = vector->capacity;
}

int main() {
    Vector * vec = Vector_create();

    Vector_push(vec, 10);
    Vector_push(vec, 20);
    Vector_push(vec, 0);
    Vector_push(vec, 18);

    for(int i = 0; i < vec->size; i++) {
        printf("%d\t", (vec->data)[i]);
    }
    printf("\n");

    int popped = Vector_pop(vec);
    printf("popped: %d\n", popped);

    Vector_resize(vec, 12);
    for(int i = 0; i < vec->size; i++) {
        printf("%d\t", (vec->data)[i]);
    }
    printf("\n");
}