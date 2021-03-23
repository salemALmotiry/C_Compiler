#include "global.h"


void main()
{
	input 	= fopen("file.exp",	"r");
	if (input == NULL){
	printf("file doesn't exist or could not open it'"); exit (0);}
	output 	= fopen("file.obj" , "w");
	error2 	= fopen("file.err",	"w");
	init();
	parse();
	exit(0);
	//test com
	fclose	(	input	);
	fclose	(	output	);
	fclose	(	error2	);
}
