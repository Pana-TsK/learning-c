#include <stdio.h>

#define MAXLENGTH 1000

void expand(char s[], char t[]);

/* main function */
int main() {

    char s[MAXLENGTH] = "a-z,A-Z,a-X,a-b-c -a, a-, 1-9\na-z0-9"; // input string
    char t[MAXLENGTH];

    expand(s, t);

    printf("normal string:  %s\n", s);
    printf("expanded string:%s\n", t);


    return 0;
}

void expand(char s[], char t[]) {
    int i, j, c;
    int prior = 0, post = 0;

    for(i=0,j=0; s[i] != '\0' && i < MAXLENGTH ; i++) {
        c = s[i];

        // read from second character on to avoid out-of-bounds read
        if (i > 1)
            prior = s[i-1], post = s[i+1];

        if (c == '-'){
            // logic to expand the '-' for letters and numbers
            if (((prior < post) && (prior >= 97 && post <= 122) || (prior >= 65 && post <= 90) || (prior >= 48 && post <= 57)) && ((post - prior) > 1)) {
                for(int expchar = prior + 1; expchar < post; expchar++) {
                    t[j++] = expchar;
                }
            }
            else {
                t[j++] = c;
            }
        } 
        else {
            t[j++] = c;
        }
    }

    // terminate the string
    t[j++] = '\n'; // added this for ease of reading for printing
    t[j++] = '\0';
}