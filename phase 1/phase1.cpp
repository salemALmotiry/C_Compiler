#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>

int lookahead;

void expr(void);
void term(void);
void match(int);
void error(void);

int main(void)
{
    lookahead = getchar();
    expr();
    putchar('\n'); /* adds trailing newline character */
}


void term(void)
{
    if (isdigit(lookahead)) {
        putchar(lookahead);
        match(lookahead);
    }
    else
        error();
}

void match(int t)
{
    if (lookahead == t)
        lookahead = getchar();
    else
        error();
}



void error(void)
{
    printf("syntax error\n"); /* print error message */
    exit(1); /* then halt */
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


