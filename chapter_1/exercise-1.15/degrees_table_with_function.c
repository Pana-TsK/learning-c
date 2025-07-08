#include <stdio.h>

float fahr_to_celsius(float fahr) {
    return 5.0 * (fahr - 32.0) / 9.0;

}

int main() {
    printf("fahr\tcelsius\n");
    int lower, upper, step;
    float fahr;


    lower = 0;
    upper = 300;
    step = 25;

    
    for(fahr=upper; fahr>=lower; fahr = fahr - step) {
        printf("%3.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr));
    }
    return 0;
}

