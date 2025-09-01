#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // ---- code to benchmark ----
    for (volatile long i = 0; i < 100000000; i++) ;
    // ---------------------------

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Elapsed CPU time: %f seconds\n", cpu_time_used);
    return 0;
}
