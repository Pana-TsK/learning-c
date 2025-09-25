#include <stdio.h>

void print_binary(unsigned int num);
unsigned invert(unsigned x, int p, int n);

int main() {


    return 0;
}


unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p - n + 1));
}

// Helper function to print unsigned int in binary for verification
void print_binary(unsigned int num) {
    int i;
    for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) { // Add space every 8 bits for readability
            printf(" ");
        }
    }
    printf("\n");
}