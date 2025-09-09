#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "vector.h"

int main() {
    vector * vec = init();

    push(vec, 14);
    push(vec, 16);

    push(vec, 18);
    push(vec, 15);
    
    push(vec, 12);
    push(vec, 13);

    print(vec);

    int veclen = sizeof(vec) / sizeof(vec->v[0]);

    quicksort(vec, 0, 6);

    print(vec);
}