#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

void strcopy(char *s, char *t);

int main () {
    char t[MAXLENGTH];
    strcopy("hello, world\n", t);
    printf("the new string is: %s\n", t);

    char u[MAXLENGTH];

    strcopy("let's see if the string is reusable\n", u);
    printf("the new string is: %s\n", u);

    char v[MAXLENGTH];

    strcopy("and short?\n", v);
    printf("the new string is: %s\n", v);

    return 0;
}

void strcopy(char *s, char *t) {

    for (;*s != '\0'; s++) {
        *t = *s;
        t++;
    }
}