#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main() {

    fibseq * f = init();
    fibonacci(f, 20);

    print(f);
}

fibseq * init() {
    
    fibseq * f = malloc(sizeof(fibseq));
    f->cap = INIT_CAP;
    f->len = 0;
    f->array = malloc(f->cap * sizeof(int));

    return f;
}


int fibonacci(fibseq * f, int n) {
    if (n <= 1) {
        f->array[n] = 1;
        if (f->len <= n) f->len = n + 1;
        return 1;
    }

    if (n < f->len) {
        return f->array[n];
    }

    
    int a = fibonacci(f, n - 1);
    int b = fibonacci(f, n - 2);

    int result = a + b;

    if (f->len >= n) {
        if (f->len >= f->cap) {

            f->cap *= 2;

            int * temp_ptr = realloc(f->array, f->cap * sizeof(int));
            if (! temp_ptr) {
                fprintf(stderr, "error reallocating more space for the array.\n");
            }
            f->array = temp_ptr;
            printf("reallocating more space for the array. New capacity: %d\n", f->cap);

        }
        
    f->len++;
    f->array[n] = result;

    }

    return result;

}

void print(fibseq * fib) {

    printf("[");
    for(int i = 0; i< fib->len; i++) {
        printf("%d", fib->array[i]);

        if (i < fib->len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}