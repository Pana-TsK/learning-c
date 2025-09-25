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

    return 0;
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    
}