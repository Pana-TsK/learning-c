#include <stdio.h>
#include <limits.h>

int main() {
    printf("via just printing out the values:\n");
    printf("maximum int value: %d\n", INT_MAX);
    printf("maximum long value: %ld\n", LONG_MAX);
    printf("maximum short value: %d\n", SHRT_MAX);

    printf("other values will be obtained via a similar approach");
    
    printf("via manual calculation:\n");
    short i;

    for (i = 0; i >= 0; i++);
    i--;

    printf("only did the short for demonstration purposes: %d\n", i);
    return 0;
}

