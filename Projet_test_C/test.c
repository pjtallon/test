//essai du code c sous gcc et windows
// #define UL
#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.h"

int main(int argc, char **argv)
{
	printf("Test d'un bout de code en  C\n");

#ifdef PARSER_H
	print_arguments( argc, argv);
#endif

#ifdef UL
	printf("Read command\n");
	read_cmd(argc, argv);
	printf("Free memory\n");
	free_cmd(argc, argv);
	printf("End\n");
#endif
	getchar;
	return 0;
}
