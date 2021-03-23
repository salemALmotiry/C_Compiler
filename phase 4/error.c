#include "global.h"


	void error(char* m)
{
	fprintf(error2, "line %d: %s\n", lineno, m);
	exit(1);
}

