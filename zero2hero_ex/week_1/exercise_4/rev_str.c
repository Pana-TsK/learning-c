#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

void reverse_str(char *s);

int main() {
    char s[MAXLENGTH];

    scanf("%[^\n]", s);

    reverse_str(s);
    printf("%s\n", s);

    return 0;
}

void reverse_str(char * ps) {
    char *pi, *pj;
    char temp;
    
    // increment p to the final position
    for (pj = ps; *pj != '\0'; pj++)
    ;
    pj--; // one back for '\0'

    // perform the swap
    for (pi = ps; pi < pj ; pi++, pj--) {
        temp = * pi;
        * pi = * pj;
        * pj = temp;

    }

}
