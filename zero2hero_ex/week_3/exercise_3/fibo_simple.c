#include <stdio.h>
#include <stdlib.h>

int fibo(int n) {
    if (n <= 1) {
        return 1; 
    }
    
    return (fibo(n - 1) + fibo(n - 2));
}

int main() {
    int x = fibo(7);
    printf("%d \n", x);

    int y = fibo(8);
    printf("%d \n", y);

    int z = fibo(9);
    printf("%d \n", z);

}