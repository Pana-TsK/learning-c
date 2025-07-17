#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLENGTH 1000

void atob(int i, char s[], int base);
void reverse(char s[]);

int main() {
    int i = 16;
    char s[MAXLENGTH];

    atob(i, s, 8); // 16 in base 8 is 20

    printf("dig: %d\n", i);
    printf("str: %s\n", s); // Should print "20"

    // Test with a negative number
    int neg_i = -16;
    char s_neg[MAXLENGTH];
    atob(neg_i, s_neg, 8);
    printf("dig: %d\n", neg_i);
    printf("str: %s\n", s_neg); // Should print "-20"

    // Test with hex

    int hex_i = 44;
    char hex_s[MAXLENGTH];
    atob(hex_i, hex_s, 16);
    printf("dig: %d\n", hex_i);
    printf("str: %s\n", hex_s); // Should print "-20"

    return 0;
}

void atob(int n, char s[], int base) {
    int sign, i = 0;
    int digit;

    const char digits[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

    printf("sign check\n");
    // handle the sign
    if ((sign = n) < 0) 
        n = -n;

    printf("zero check\n");
    // handle the special case where i = 0
    if (n == 0){
        s[i++] = '0';

    } else {
    
    while(n > 0) {
        // get the digit via remainder of division
        digit = n % base;

        // convert this character into the correct representation
        s[i++] = digits[digit];
        n /= base; //divide a base away each iteration
        }
    }

    if (sign < 0) {
            s[i++] = '-';
        }
        
    s[i++] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    int len = strlen(s);
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}