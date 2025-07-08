#include <stdio.h>

int main() {
    /*
    Count digits, white spaces, and other characters,
    and then, turn these results into a histogram.
    */

    int c;
    int nspaces = 0; // Initialize directly
    int nother = 0;  // Initialize directly
    int ndigits = 0; // Initialize directly

    printf("Enter text (Ctrl+D or Ctrl+Z to end):\n");

    while ((c = getchar()) != EOF) {
        // categorize and increment the correct parameter
        if (c == ' ' || c == '\n' || c == '\t') {
            ++nspaces;
        } else if (c >= '0' && c <= '9') {
            ++ndigits;
        } else {
            ++nother;
        }
    }

    // Print the counts
    printf("\n--- Counts ---\n");
    printf("Digits: %d\n", ndigits);
    printf("Whitespaces: %d\n", nspaces);
    printf("Other characters: %d\n", nother);

    // Print the histogram
    printf("\n--- Histogram ---\n");

    // Digits histogram
    printf("Digits:      ");
    for (int i = 0; i < ndigits; ++i) {
        putchar('#');
    }
    putchar('\n');

    // Whitespaces histogram
    printf("Whitespaces: ");
    for (int i = 0; i < nspaces; ++i) {
        putchar('#');
    }
    putchar('\n');

    // Other characters histogram
    printf("Other:       ");
    for (int i = 0; i < nother; ++i) {
        putchar('#');
    }
    putchar('\n');

    return 0;
}