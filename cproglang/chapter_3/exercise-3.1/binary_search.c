#include <stdio.h>

#define MAXLENGTH 10

int binsearch(int x, int v[], int n);

int main() {

    int v[] = {10, 15, 20, 25, 30};
    int n = 5;
    int x = 20;

    int num = binsearch(x, v, n);

    printf("number found at position %d\n", num);
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high)/2;

        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    /* check for equality */

    if (low < n && v[low] == x) 
        return low;
    else
        return -1; /* no match */


}