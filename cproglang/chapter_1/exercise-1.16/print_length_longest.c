#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy (char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        // print line
        printf("%d\t%s\n", len, line);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/*getline: read a line into s, and return its length*/
int getline(char s[], int lim) {

    int c, i; // index and character grabbed

    //use a for loop limited to the length of lim
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {  
        // place the char in the string
        s[i] = c;
    }
    // handle the newline character event
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    // place the \o character to indicate the end of the string
    s[i] = '\0';
    return i;
}

/* copy values from one string to another*/
void copy (char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}