#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include "emitter.c"
// #include "error.c"
// #include "init.c"
// #include "lexer.c"
// #include "parse.c"
// #include "symbol.c"

#define BSIZE  	128
#define NONE   	-1
#define EOS    	'\0'

#define NUM    	256
#define DIV    	257
#define MOD    	258
#define ID     	259
#define DONE   	260
#define IF		300
#define THEN 	301
#define WHILE 	302
#define DO 		303
#define BEGIN 	304
#define END 	305
#define REPEAT 	306
#define UNTIL 	307



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
