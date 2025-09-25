#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLENGTH 1000

void spaced_atoi(int i, char s[], int min);
void reverse(char s[]);

int main() {

    int i = -83;
    char s[MAXLENGTH];

    spaced_atoi(i, s, 10);
    
    printf("str: %s\n", s);

    return 0;
}

void spaced_atoi(int n, char s[], int min) {
    int i = 0, sign;

    if (n == INT_MIN) {
        long long temp_n = n;
        temp_n = - temp_n;

        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0 );
        s[i++] = '-';
        s[i] = '\0';

        while ((i < min) > 0) {
        s[i++] = ' ';
        }   

        reverse(s);
        return;
        }

    if ((sign = n) < 0) {
        n = -n;
    }

    do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0 );
        if (sign < 0)
        s[i++] = '-';
        
    while ((i <= min)) {
        s[i++] = ' ';

    }

    s[i++] = '\0';

    reverse(s);

}

void reverse(char s[]) {
    int i, j;
    char temp;
    int length = strlen(s);

    for(i=0, j = length-1; i < j ; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}
