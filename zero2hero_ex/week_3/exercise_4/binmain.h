#ifndef MAIN_H
#define MAIN_H

#define INIT_CAP 5

typedef struct array {
    int * array;
    int len;
} array;

void print_array(array * v);

#endif