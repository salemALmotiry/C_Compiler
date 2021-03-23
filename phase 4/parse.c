#include "global.h"
int lookahead;
void expr();
void rest();
void term();
void match(int t);
void factor();
void stmt();
void cs();
extern char lexemes[];
int lookahead;
int tok;
extern struct entry symtable[];

void parse()
{
		lookahead = lexan();
		while (lookahead != DONE ){
		       stmt(); match(DONE);
		}
}

void expr()
{
	int t;
	term();

	while(1)
	   switch (lookahead) {
	     case '+': case '-':
	        t = lookahead;
	        match(lookahead); term(); emit(t, NONE);
	       continue;
	    default:
	       return;
	}
}

void stmt(){
	tok = tokenval;
	switch (lookahead){
		case ID:
			match(ID);
			match('=');
			expr();
			fprintf(output, "pop %s\n", symtable[tok].lexptr); 
			break;
			
		case IF:
			match(IF);
			match('(');
			expr();
			match(')');
			match(THEN);
			fprintf(output , "pop r2\ncmp r2,0\nbe else\n");
			stmt();
			fprintf(output , "else:\n");
			break;
			
		case REPEAT:
			match(REPEAT);
			fprintf(output, "repeat:\n");
			cs();
			match(UNTIL);
			match('(');
			expr();
			match(')');
			fprintf(output , "pop r2\ncomp r2,0\nbe repeat\n");
			break;
			
		case WHILE:
			match(WHILE);
			fprintf(output , "while\n");
			match('(');
			expr();
			match(')');
			match(DO);
			fprintf(output , "pop r2\ncmp r2,0\nbe endwhile\n");
			stmt();
			fprintf(output ,"b while\nendwhile\n");
			break;
			
		case BEGIN:
			match(BEGIN);
			cs();
			match(END);
		default:
			error("syntax error");

	}

}


void cs(){
	while ((lookahead !=END) && (lookahead !=UNTIL)){
		stmt();
		match(';');
	}
}
void term()
{
	int t;
	factor();
	while(1)
	     switch (lookahead) {
	        case '*': case '/': case DIV: case MOD:
		t = lookahead;
		match(lookahead); factor(); emit(t, NONE);
		continue;
	         default:
		return;
	}
}
void factor()
{
	switch (lookahead) {
	case '(':
		match ('('); expr(); match(')'); break;
	case NUM:
		emit(NUM, tokenval);
		match(NUM); break;
	case ID:
		emit(ID, tokenval); 
		match(ID); 
		break;
	default:
		error("syntax error");
	}
}

void match(t)
	int t;
{
	if (lookahead == t)
		lookahead = lexan();
	else error ("syntax error");
}

