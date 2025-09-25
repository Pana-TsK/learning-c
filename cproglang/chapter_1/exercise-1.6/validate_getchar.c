#include <stdio.h>

main() {
    // verify what getchar() != EOF evaluates to
    ; // I know the braces might not be necessary. Better safe than sorry.

    printf("%d\n", (getchar() != EOF));

    return 0;
}
// this evaluates always to one (true)