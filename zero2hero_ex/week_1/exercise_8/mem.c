#include <stdio.h>
#include <stdlib.h>


void memcopy(const void * src, void * dest, size_t n) {
    const unsigned char * s = src;
    unsigned char * d = dest;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
}

void memmoove(const void * src, void * dest, size_t num) {
    const unsigned char * s = src;
    unsigned char * d = dest;

    for (size_t i = 0; i < num; i++) {
        d[i] = s[i];
    }

    d[num] = '\0';
}


int main() {
    int a = 10;
    int b = 0;

    printf("b before the assignment: %d\n", b);
    memcopy(&a, &b, sizeof(int));
    printf("b after assignment: %d\n", b);


    char c[10] = "Hello    ";
    char d[10] = "";
    memmoove(c, c+2, 8);

    printf("%s\n", d);
}