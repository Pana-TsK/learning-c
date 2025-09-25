#include <stdio.h>

int main() {
    int octal = 0x64;
    int dec;

    printf("octal number: %x\n", octal);

    dec = octal + 0;
    printf("decimal  number: %d\n", dec);

    return 0;
}