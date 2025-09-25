#include <stdio.h>

int main() {
    int c; //current character being read
    int word_length; //length of the word currently being tracked
    int i; //index to keep track of which word is being adressed
    int x; // index for the for loop

    word_length = 0;
    i = 0;



    while ((c = getchar()) != EOF) {
        // managing word logic
        if (c == ' ' || c == '\t' || c == '\n') {
            x = 0;
            printf("%d\t", i);
            for (x; x < word_length; ++x) {
                putchar('#');
            }
            ++i; // increment the index
            printf("\n"); //generate a newline
            word_length = 0; // reset the word length
        }
        else {
            ++word_length;
        }

    }

    return 0;
}