#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I want to do this via recursion.
// the taylor series takes the value to be approximated, substracts it from 0, and
// sets up the function to run for i cycles.

/* calculate the factorial recursively. long long because high chance of overflow. */
static long long factorial(int n){
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

/* calculate n_max elements in the series. */
static double taylor_sin(int n, float x) {
    if (n == 0)
        return x;

    double term = pow(-1, n) * pow(x, (2*n + 1)) / factorial((2*n + 1));
    return term + taylor_sin(n-1, x);
}

double my_sin(float x) {
    return taylor_sin(3, x);
}

int main(int argc, char ** argv) {
    double x = 3.1415692535;
    double s = my_sin(x);
    
    printf("predicted result: %f\n", s);
    printf("result from built-in library: %f", sin(x));
    return 0;
}