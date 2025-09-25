#include <stdio.h>

#define TABWIDTH 8

int main() {
    int c, spaces = 0, pos = 0;


    while((c = getchar()) != EOF) {

        if (c == ' ') {
            spaces++;
            pos++;

        } else {
            if (spaces > 0) {
                // calculate the amount of spaces the tab is going to replace
                int tabs = (pos - spaces) / TABWIDTH;
                int rem = (pos - spaces) % TABWIDTH;

                // place the amount of tabs necessary

                while (spaces >= TABWIDTH - rem) {
                    putchar('\t');
                    spaces -= TABWIDTH - rem;
                    rem = 0;
                }

                // place the amount of leftover spaces

                while (spaces-- > 0) {
                    putchar(' ');
                }

                spaces = 0;

            }
            
            // print out the character
            putchar(c);

            if (c == '\n') {
                pos = 0;
            } else {
                pos++;
            }
        }
    }
}