#include "global.h"


void main()
{
	input 	= fopen("file.exp",	"r");
	if (input == NULL){
	printf("the file is empty"); exit (0);}
	output 	= fopen("file.obj" , "w");
	error2 	= fopen("file.err",	"w");
	init();
	parse();
	exit(0);
	
	fclose	(	input	);
	fclose	(	output	);
	fclose	(	error2	);
}
