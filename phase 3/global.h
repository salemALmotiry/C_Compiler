#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE  128
#define NONE   -1
#define EOS    '\0'

#define NUM    256
#define DIV    257
#define MOD    258
#define ID     259
#define DONE   260



int tokenval;
FILE  * input;
FILE  * output;
FILE  * error2;

int lineno;

struct entry {
   char *lexptr;
   int token;
   };
#endif
