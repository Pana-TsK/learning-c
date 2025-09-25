#include <stdio.h>

/* Generate a table containing Fahrenheit to celsius temperatures*/

int main() {
    float fahr, celsius;
    float lower, upper, step; // specify the while loop and which numbers we want in the table

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower; //set the temperature at which we want to start

    // print heading
    printf("fahr\tcelsius\n");

    for(fahr=upper; fahr>=lower; fahr = fahr - step) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }
}