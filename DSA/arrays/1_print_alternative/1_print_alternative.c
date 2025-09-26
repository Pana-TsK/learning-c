#include <stdio.h>
#include <stdlib.h>

void print_alternative(int * a, int len) {
    for(int i = 0; i < len; i += 2) {
        printf("%d ", a[i]);
    }
}

void print_alternative_recursive(int * a, int i, int len){
    // return when len > i
    if (i > len) 
        return;
    
    printf("%d ", a[i]);;
    
    print_alternative_recursive(a, i + 2, len);
}

int main(int argc, char ** argv) {
    // perform with linear method
    int a[] = {1, 2, 3, 4, 5};

    printf("iterative: ");
    print_alternative(a, 5);
    printf("\n");

    printf("recursive: ");
    print_alternative_recursive(a, 0, 5);
    printf("\n");

    return 0;
}