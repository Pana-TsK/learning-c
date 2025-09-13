#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    

    char name[] = "Panagiotis";

    FILE * fptr = fopen("write_digits.dat", "wb+");
    fwrite(name, sizeof(char), 11, fptr);
    fclose(fptr);
}