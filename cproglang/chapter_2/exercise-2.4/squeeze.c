#include <stdio.h>

#define MAXLENGTH 1000

void squeeze(char string1[], char string2[]);

int main() {
    char string1[MAXLENGTH];
    char string2[MAXLENGTH];

    // get the strings with fgets (for testing purposes)
    fgets(string1, MAXLENGTH, stdin);
    fgets(string2, MAXLENGTH, stdin);

    printf("string 1 before cleaning: %s\n", string1);
    printf("string 2: %s\n", string2);
    
    // simply call the squeeze from the main function
    squeeze(string1, string2);

    printf("string 1: %s\n", string1);
    

    return 0;
}

void squeeze(char string1[], char string2[]) {
    // set up the increment
    int i, j, k, match;

    // increment over the first string, and reset j every cycle
    for(i=0, j=0; string1[j] != '\0'; i++) {
        // increment over the second string
        match = 0;

        for(k=0; string2[k] != '\0'; k++) {
            if (string1[i] == string2[k]) {
            match = 1;
            }
        }

        if (!match) {
                string1[j++] = string1[i];
                match = 0;
            }

        // stop once the whole string has been copies
    }
    // add the '\0'
    string1[++i] = '\0';

}