#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 1000
#define NUMBER '0'
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

void peek(void);
void swap(void);
void clear(void);

/* external variables to the stack */
int sp = 0;
double val[MAXVAL];

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
    if isalpha(type) {
        printf("detected a letter.");
    } else {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push (pop() + pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push (pop() / op2);
                break;
            case '?':
                peek();
                break;
            case '^':
                swap();
                break;
            case '$':
                clear();
                break; 
            case '\n':
                printf("result:\t%g\n", pop());
                break;
            default:
                printf("error: %s is not a command\n", s);
                break;
            }
        }
    }

    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full.\n");
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else
        printf("stack empty. Add elements before trying again.\n");

}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void peek(void) {
    if (sp > 0) {
        for (int i = 3; i > 0 && sp - i >= 0; i--) {
            printf("%g\t", val[sp - i]);
        }
    printf("\n");
    }
    else
        printf("error: stack is empty\n");
}

void swap(void) {
    if (sp > 1) {

        /* perform the position swap */
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else {
        printf("error: stack does not have enough elements to perform the swap.\n");
    }
}

void clear(void) {
    for(sp; sp > 0; sp--)
    ;
}