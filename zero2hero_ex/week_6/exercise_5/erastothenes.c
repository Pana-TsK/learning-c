#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFSIZE 50

int * sieve(size_t n);
int * extract_primes(size_t n, int * arr, int * arr_len);


int main(int argc, char ** argv) 
{

    int n = 100;
    int *arr = sieve(n);

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\n",i + 2, arr[i]);
    }
    printf("\n");

    int arr_len;
    int * primes = extract_primes(n, arr, &arr_len);

    for(int i = 0; i < arr_len; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");

    free(arr);
    free(primes);
    
    return 0;
}

int * sieve(size_t n) 
{
    if (n < 2) {
        printf("n must be larger than 1.\n");
        return NULL;
    }

    int * arr = calloc(n, sizeof(int));
    if (!arr) {
        perror("error allocating sieve array");
        exit(1);
    }

    for(int i = 2; i < n; i++) {
        int product = 0;
        for (int j = 2; (product = i * j) < n; j++ ) {
            arr[product] = 1;
        }
    }

    return arr;
}

int * extract_primes(size_t n, int * arr, int * arr_len)
{
    int * primes = malloc(sizeof(int) * BUFSIZE);
    if (!primes) {
        perror("error allocating primes array");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            primes[j++] = i;
        }
    }

    // reallocate the array to the correct size
    int * tmp = realloc(primes, sizeof(int) * j);
    if (tmp) {
        primes = tmp;
    }

    * arr_len = j;
    return primes;
}