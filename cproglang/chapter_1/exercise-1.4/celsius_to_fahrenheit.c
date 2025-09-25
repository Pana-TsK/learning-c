#include <stdio.h>

/* Generate a table containing celsius to fahrenheit temperatures*/

int main() {
    float fahr, celsius;
    float lower, upper, step; // specify the while loop and which numbers we want in the table

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower; //set the temperature at which we want to start

    // print heading
    printf("celsius\tfahrenheit\n");

    for(celsius=lower; celsius<=upper; celsius = celsius + step) {
        fahr = (9 * celsius / 5) + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }
}