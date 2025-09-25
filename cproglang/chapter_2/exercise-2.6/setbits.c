#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void print_binary(unsigned int num);

int main() {
    unsigned int x_val, y_val;
    int p_val, n_val;
    unsigned int result;

    // Test Case 1: Basic replacement
    x_val = 0b11110000; // 240 in decimal
    p_val = 5;          // Position 5 (0-indexed from right)
    n_val = 3;          // 3 bits
    y_val = 0b00000101; // 5 in decimal (rightmost 3 bits are 101)
    // Expected: x_val bits at 5,4,3 (110) become 101.
    // Original: 1111 0000
    // p=5, n=3 means bits at index 5,4,3. (0-indexed from right)
    // So, bits 110 (at 5,4,3) should become 101.
    // Result:   1111 0100 (244)
    printf("Test Case 1:\n");
    printf("x = %u (", x_val); print_binary(x_val); printf(")\n");
    printf("y = %u (", y_val); print_binary(y_val); printf(")\n");
    printf("p = %d, n = %d\n", p_val, n_val);
    result = setbits(x_val, p_val, n_val, y_val);
    printf("Result = %u (", result); print_binary(result); printf(")\n");
    printf("Expected result (binary): 11110100\n\n");


    // Test Case 2: Replacing bits at the very right
    x_val = 0b10101010; // 170
    p_val = 2;
    n_val = 3;
    y_val = 0b00000111; // 7 (rightmost 3 bits are 111)
    // Original: 1010 1010
    // p=2, n=3 means bits at index 2,1,0. (010) should become 111.
    // Result:   1010 1111 (175)
    printf("Test Case 2:\n");
    printf("x = %u (", x_val); print_binary(x_val); printf(")\n");
    printf("y = %u (", y_val); print_binary(y_val); printf(")\n");
    printf("p = %d, n = %d\n", p_val, n_val);
    result = setbits(x_val, p_val, n_val, y_val);
    printf("Result = %u (", result); print_binary(result); printf(")\n");
    printf("Expected result (binary): 10101111\n\n");

    // Test Case 3: Replacing bits in the middle
    x_val = 0b11111111; // 255
    p_val = 4;
    n_val = 2;
    y_val = 0b00000000; // 0 (rightmost 2 bits are 00)
    // Original: 1111 1111
    // p=4, n=2 means bits at index 4,3. (11) should become 00.
    // Result:   1110 0111 (231)
    printf("Test Case 3:\n");
    printf("x = %u (", x_val); print_binary(x_val); printf(")\n");
    printf("y = %u (", y_val); print_binary(y_val); printf(")\n");
    printf("p = %d, n = %d\n", p_val, n_val);
    result = setbits(x_val, p_val, n_val, y_val);
    printf("Result = %u (", result); print_binary(result); printf(")\n");
    printf("Expected result (binary): 11100111\n\n");

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned int mask_clear_x = ~(~0u << n);
    x = x & ~(mask_clear_x << (p - n + 1));
    unsigned int y_n_bits = y & mask_clear_x;
    unsigned int y_positioned = y_n_bits << (p - n + 1);
    return x | y_positioned;

}

// Helper function to print unsigned int in binary for verification
void print_binary(unsigned int num) {
    int i;
    for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) { // Add space every 8 bits for readability
            printf(" ");
        }
    }
    printf("\n");
}