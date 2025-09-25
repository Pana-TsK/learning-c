#include <stdio.h>

int main() {

    int i, c;
    int lim = 1000;
    // original for loop:
    for(i = 0; i < lim-1 && (c = getchar()) != '\n' && c != 'EOF'; i++);

    // without using boolean logic
    for(i = 0; ((i < lim-1) + ((c = getchar()) != '\n') + (c != 'EOF')) == 3; i++);

    return 0;
}