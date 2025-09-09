#ifndef VECT_H
#define VECT_H

#define INIT_CAP 5

typedef struct vector {
    int * v;
    int len;
    int cap;
} vector;

vector * init();

void push(vector * vec, int num);
void print(vector * vec);



#endif