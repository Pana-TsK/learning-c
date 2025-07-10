#include <stdio.h>

#define TABWIDTH 10; // amount of lines before a tabstop is hit

int main() {

    int i;
    int c, col, spaces;

    col = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            // handle tab spacing logic
            spaces = TABWIDTH - col % TABWIDTH;
            for (i = 0; i < spaces; ++i)
                putchar(' ');
            col = col + spaces;
        }
        else {
            putchar(c);
            col = col + 1;

            // logic to go to next line
            if (c == '\n') {
                col = 0;
            }
        }
    }

    return 0;
}