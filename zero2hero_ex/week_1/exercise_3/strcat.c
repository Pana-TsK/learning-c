/* bare bones remake of the string strcat functionality */

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

void strct(char *s, char *t);

int main() {
    char s[MAXLENGTH] = "let's see ";
    char t[MAXLENGTH] = "if this works\n";

    strct(s, t);
    printf("%s", s);

    return 0;

}

void strct(char *s, char *t) {
    for ( ; *s != '\0'; ++s); // increment the s pointer to the terminator;
    for (; *t != '\0'; t++) {
        *s = *t;
        s++;
    }
    s++;
    s = '\0';
}