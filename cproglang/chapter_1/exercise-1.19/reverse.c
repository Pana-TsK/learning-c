#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max_length);
void reverse(char line[], char reverse[], int length);

int length;

int main() {

    char input_line[MAXLINE];
    char reversed_line[MAXLINE];

    while(length = getline(input_line, MAXLINE)) {

        reverse(input_line, reversed_line, length);
        printf("reversed string: %s", reversed_line);

    }

    return 0;
}

int getline(char line[], int max_length){

    int c;
    int i;

    for(i=0; i <= max_length && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    return i;
}

void reverse(char old[], char rev[], int length){

    int i = length - 1;
    int j = 0;

    for (i; i >= 0 ; --i) {

        // condition to skip '\n' and '\0'
        if (old[i] != '\n' || old[i] != '\0'){
            rev[j] = old[i];
            ++j;
        }
    }

    // append '\n'
    rev[j] = '\n';
    ++j;

    //append '\0'
    rev[j] = '\0';

}