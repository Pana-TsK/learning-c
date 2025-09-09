#ifndef FIB_H
#define FIB_H

#define INIT_CAP 5

typedef struct fibseries {
    int * array;
    int len;
    int cap;
} fibseq;

fibseq * init();
int fibonacci(fibseq * fib, int n);
void print(fibseq * fib);

#endif