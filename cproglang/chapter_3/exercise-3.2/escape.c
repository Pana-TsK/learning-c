#include <stdio.h>

#define MAXLENGTH 1000

void escape(char s[], char t[]);

int main() {
    /* test code & cases */
    char input[MAXLENGTH] = "Hello\tWorld\nPana here";
    char output[MAXLENGTH];

    escape(input, output);

    printf("input: %s\n", input);
    printf("output: %s\n", output);

    return 0;
}

void escape(char s[], char t[] ){
    int i = 0, j = 0;
    char c;

    while ((c = s[i++]) != '\0') {
        switch(c) {
            case '\t': 
                t[j++] = '\\';
                t[j++] = 't';
                break;

            case '\n': 
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            
            default:
                t[j++] = c;
                break;
        }
    }

}