#include <stdio.h>

/*
Fold will take a line that is too long and break it, so two shorter lines are formed instead.
Lines are broken at the first character post a space.
If no space is present, an error message is printed via printf.
*/

#define LINELENGTH 40 // maximum length of a line.
#define MAXLENGTH 1000 // maximal length of a string (overflow)

int copy(char line[], int max);
void split_print_string(char input_string[], int len);

int main() {

    int len;
    char line[MAXLENGTH];

    while((len = copy(line, MAXLENGTH)) != 0) {
        split_print_string(line, len);
    } 

    return 0;
}

/* copy: function for creating string */
int copy(char line[], int max) {
    int c, i = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n' && i < max; i++) {
        line[i] = c;
    }
    // append the '\n'
    if (c == '\n'){
        line[i] = '\n';
        i++;
    }
    // append the end of string character
    line[i] = '\0';

    return i - 1;
}

/* split the string into smaller substrings, and print these strings out. */
void split_print_string(char raw_string[], int len) {
    int start = 0;

    while (start < len) {
        int end = start + LINELENGTH;
        if (end >= len)
            end = len;

        int fold = -1;
        for (int i = end - 1; i >= start; i--) {
            if (raw_string[i] == ' ') {
                fold = i;
                break;
            }
        }

        if (fold != -1) {
            for (int i = start; i < fold; i++) putchar(raw_string[i]);
            putchar('\n');
            start = fold + 1;
        } else {
            // no space found, print the whole segment without error
            for (int i = start; i < end; i++) putchar(raw_string[i]);
            putchar('\n');
            start = end;
        }
    }
}

