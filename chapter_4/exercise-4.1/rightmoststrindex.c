#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int rightmstrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    

    while (get_line(line, MAXLINE) > 0)
        if (rightmstrindex(line, pattern) >= 0) {
            printf("%s", line);
        }

    return 0;
}

int get_line(char s[], int lim) {
    int i = 0, c;

    while((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')) {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = '\n';
    }

    s[i++] = '\0';

    return i;

}

int rightmstrindex(char source[], char searchfor[]) {
    int i, j, k;
    int len = strlen(source);
    int slen = strlen(searchfor);
    
    for(i = len - 1; i >= 0; i--) {
        for(j = i, k = 0 ; searchfor[k] != '\0' && source[j] == searchfor[k] ; j++, k++)
        ;
        if (k > 0 && searchfor[k] == '\0')
            return i;
    }

    return -1;
}