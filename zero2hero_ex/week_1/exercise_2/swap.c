#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {
    int a = 3;
    int b = 4;
    printf("before swapping: a is %d and b is %d\n", a, b);
    swap(&a, &b);
    printf("after swapping: a is %d and b is %d\n", a, b);

    return 0;
}

void swap(int *py, int *px) {
    int temp;

    temp = *py;
    *py = *px;
    *px = temp; 
}