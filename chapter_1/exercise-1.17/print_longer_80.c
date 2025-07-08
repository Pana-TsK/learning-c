#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max_length);
void copy(char to[], char from[]);

int main() {

    // define main() variables
    int len;
    char line[MAXLINE];
    
    //read in all the texts and print output
    while(len = getline(line, MAXLINE)) {
        if (len >= 80) {
            printf("%s\n", line);
        }
    }

    return 0;
}

// function for fetching a line of text
int getline(char line[], int max_length) {
    int c, i;
    for(i = 0; i < max_length && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    // handle coming across a \name
    if (c == '\n') {
        line[i] == c;
        ++i;
    }
    // place the final \o characted to indicate end of the string
    line[i] = '\0';
    return i;
}