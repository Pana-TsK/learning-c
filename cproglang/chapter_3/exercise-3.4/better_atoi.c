#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLENGTH 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    int i = -413255;
    char s[MAXLENGTH];

    itoa(i, s);

    printf("int:    %d\n", i);
    printf("string: %s\n", s);

    return 0;
}

/*
It's common for itoa functions to not handle the sign well due to the line
n = -n,
since there is one more negative numbers than positive numbers in two complement's integers.
This can be solved by converting to a long long
*/

void itoa(int n, char s[]) {
    int i, sign;

    // handle int-min before attempting conversion
    if (n == INT_MIN) {
        long long temp_n = n;
        temp_n = - temp_n;

        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0 );
        s[i++] = '-';
        s[i] = '\0';
        
        return;
        }


    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0 );
    if (sign < 0)
       s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char temp;
    int length = strlen(s);

    for(i = 0, j = length - 1; i < j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}

