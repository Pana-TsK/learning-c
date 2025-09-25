#include <stdio.h>

int main() {

    int c;
    int spaces;

    spaces = 0;

    while((c = getchar()) != EOF){
        if (c == ' '){
            ++spaces;
        } else {
        
            if (spaces >= 1){
            putchar(' ');
            }
            putchar(c);
            spaces = 0;
        }
    }
    return 0;
}


