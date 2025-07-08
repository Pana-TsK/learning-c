#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max_line);
void rem_spaces(char from[], char to[]);

int main() {

    int length;
    char old_line[MAXLINE];
    char clean_line[MAXLINE];

    // set up the main loop
    while(getline(old_line, MAXLINE)) {
        printf("old line: %s", old_line);

        rem_spaces(old_line, clean_line);
        printf("clean line: %s\n", clean_line); 
        
    }
    return 0;
}

// fetch the line and clean it up

int getline(char line[], int max_line) {
    int c, i;

    for(i=0; i < max_line && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    // handle '\n'
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    //handle the '\0'
    line[i] = '\0';
    return i;
}

void rem_spaces(char old[], char new[]) {
    int i; // iteration index for old string
    int j = 0; // iteration index for new string
    
    int last_char_white = 0; 

    // start with removing double spaces
    for( i = 0 ; old[i] != '\0'; ++i ) {
        if (old[i] == ' ' || old[i] == '\t') {
            if (last_char_white == 0) {
                new[j] = old[i];
                ++j;
            }
            last_char_white = 1;
        } else {
            
            last_char_white = 0;

            new[j] = old[i];
            ++j;
        }
    }


    // now, j made it to the end of te string.
    // we can check if there are any trailing spaces, and can remove those before appending the '\0'

    while (new[j] == ' '|| new[j] == '\t') {
        --j;
    }
    
    new[j] = '\0';

}
