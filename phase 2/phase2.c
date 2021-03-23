
#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>

#define NUM 256

int lineno = 1;
int lookahead;
int tokenval;
void expr(void);
void term(void);
void match(int);
void error(void);
int  lexan();
int main(void)
{
    lookahead = lexan();
    expr();
    putchar('\n');
}

void match(int t)
{
    if (lookahead == t)
        lookahead = lexan();
    else
        error();
}

void expr(void)
{
    term();
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();
            putchar('+');
        }
        else if (lookahead == '-') {
            match('-');
            term();
            putchar('-');
        }
        else
            break;
    }
}
void term(void)
{
    if ((lookahead) == NUM) {
        printf("%d", tokenval);
        match(NUM);
    }
    else
        error();
}

int lexan() {
    int t;
    while (1) {
        t = getchar();
        if ((t == ' ') || (t == '\t'));
        else if (t == '\n') {
            lineno++;
        }
        else if (isdigit(t)) {
            ungetc(t, stdin);
            scanf_s("%d", &tokenval);
            return NUM;

        }
        else return t;
    }
}
void error(void)
{
    printf("syntax error\n");
    exit(1);
}

