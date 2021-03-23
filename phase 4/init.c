#include "global.h"

struct entry keywords[] = {
	"div", DIV, 
	"mod", MOD,
	"then", THEN,
	"while" , WHILE,
	"do", DO,
	"begin" , BEGIN,
	"end" , END,
	"done" , DONE,
	"if" , IF,
	"repeat",REPEAT,
	"until",UNTIL,
	0, 0
};


void init()
{
	struct entry *p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);
}

