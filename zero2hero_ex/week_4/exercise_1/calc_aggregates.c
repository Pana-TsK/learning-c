#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    FILE * fptr;

    char line[1024];
    double sum;
    size_t n;

    fptr = fopen("digits.csv", "r");
    if (!fptr) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr)) {
        char * token = strtok(line, ",");
        while (token) {
            double val = strtod(token, NULL);
            sum += val;
            n++;
            token = strtok(NULL, ","); // this works due to strtok keeping an internal null pointer, to keep track of tokenization.
        }
    }

    if (n > 0) {
        printf("items processed: %ld\n", n);
        printf("sum of items processed: %f\n", sum);
    }
}