#include <stdio.h>

int main() {
    int c, tabs, nl, blanks;

    tabs = 0;
    nl = 0;
    blanks = 0;

    while((c = getchar()) != EOF)
        if (c == '\t'){
            ++tabs;
        } else if (c == ' '){
            ++blanks;
        } else if (c == '\n'){
            ++nl;
        }
        
        printf("tabs: %d, blanks: %d, newlines: %d", tabs, blanks, nl);

    return 0;
}