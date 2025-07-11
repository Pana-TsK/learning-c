#include <stdio.h>

#define MAXLENGTH 800

int any(char string1[], char string2[]);

int main() {
    char string1[MAXLENGTH];
    char string2[MAXLENGTH];

    printf("input string1\t");
    fgets(string1, MAXLENGTH, stdin);

    putchar('\n');

    printf("input string2\t");
    fgets(string2, MAXLENGTH, stdin);

    putchar('\n');

    int index = any(string1, string2);

    printf("first letter found at index %d\n", index);

    return 0;
}

int any(char string1[], char string2[]) {

    int i, k;

    //iterate over first string
    for(i=0; string1[i] != '\0' || string1[i] != '\n'; ++i) {
        // iterate over second string
        for(k=0; string2[k] != '\0' || string1[k] != '\n'; ++k) {
            if (string1[i] == string2[k]) {
                return i;
            }
        } 
    }

    return -1;
}