/* Rudimentary implementation of the strlen function from string.h */
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

int strlength(char *s);

int main() {
    int len_1 = strlength("hello, world!");
    printf("length: %d", len_1);

    int len_2 = strlength("Panagiotis");
    printf("length: %d", len_2);
    
    return 0;
}

int strlength(char *s) {
    char *p = s;

    while (*p != '\0') {
        p++;
    }

    return p - s; // maybe this acts as an int cast
}

