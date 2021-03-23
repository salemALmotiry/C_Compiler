#include "global.h"
extern struct entry symtable[];
void emit(int t, int tval)
{
	switch(t) {
		
	case '+': 
		fprintf(output ,"pop r1\npop r2\nadd r2 ,r1\npush r2\n"); 
		break;
		
	case '-': 
		fprintf(output ,"pop r1\npop r2\nSUB r2 ,r1\npush r2\n"); 
		break;
		
	case '*': 
		fprintf(output ,"pop r1\npop r2\nMULT r2 ,r1\npush r2\n"); 
		break;
		
	case '/':
		fprintf(output ,"pop r1\npop r2\nDIV r2 ,r1\npush r2\n"); 	
		break;
		
	case DIV:
		fprintf(output ,"pop r1\npop r2\nDIV r2 ,r1\npush r2\n"); 	
		break;

	case MOD:
		fprintf(output ,"pop r2\ncmp r2 , 0 \nMOD r2 ,r1\npush r2\n"); 	
		break; 	
		
	case NUM:
		fprintf(output , "push %d \n", tval);
		break;
		
	case ID:
		fprintf(output, "push %s\n", symtable[tval].lexptr); 
		break;
		
	default:
		fprintf(output, "push(tpekn %d, tokenval %d)\n", t, tval);
	}
}
