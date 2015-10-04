#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <limits.h>

#include "parser.h"

void print_arguments(int argc, char **argv) {
	
	int argc_idx;
	char* arg_field;
	
	printf("%i\n",argc);
	
	for(argc_idx = 0; argc_idx < argc; argc_idx++) {
		strcpy(arg_field,*(argv+argc_idx));
		// assert(argc != 5);
		assert(arg_field!=NULL);
		if(arg_field!=NULL) {
			printf("%s\n",arg_field);
		}
		else {
			break;
		}
	}
	
}

/* malloc avec gestion d'une eventuelle erreur */
static void *xmalloc(size_t size)
{
	void *p = malloc(size);
	if (!p) {
		printf("Erreur d'allocation memoire\n");
	}
	return p;
}

/* Decoupage de la ligne de commande en champs, y compris les caracteres speciaux > < | et &
entree : 
- line : chaine contenant la ligne de commande
- maxw : nombre max de champs attendus
- argv[] : tableau de pointeurs qui seront connectes aux differents champs de la commande
- resultat : nombre de champs trouves
*/
int cut_cmd(char *line, int maxw, char *argv[])
{
	char *cur = line;
	int nbmots =0;
	char c;
	char *w;
	char cspec;
	char *start;

	while ((nbmots<(maxw-1)) && (c = *cur) != 0) {
		*w = 0;
		cspec = 0;
		switch (c) {
		case ' ':
		case '\t':
			/* Ignore les blancs et les tabulations */
			cur++;
			break;
		case '<':
			cspec = '<';
			cur++;
			break;
		case '>':
			cspec = '>';
			cur++;
			break;
		case '|':
			cspec = '|';
			cur++;
			break;
		case '&':
			cspec = '&';
			cur++;
			break;
		default:
			/* Autre mot */
			start = cur;
			while (c) {
				c = *++cur;
				switch (c) {
				case 0:
				case ' ':
				case '\t':
				case '<':
				case '>':
				case '|':
				case '&':
					c = 0;
					break;
				default: ;
				}
			}
			w = xmalloc((cur - start + 1) * sizeof(char));
			if (w) {
			strncpy(w, start, cur - start);
			w[cur - start] = 0;
			argv[nbmots] = w;
			nbmots++;
			}
		}
		if (cspec) {
			w = xmalloc(2 * sizeof(char));
			if (w) {
			w[0] = cspec;
			w[1] = 0;
			argv[nbmots] = w;
			nbmots++;
			}
		}
	}
	if (nbmots>(maxw-2)) {printf("trop de champs !\n");}
	argv[nbmots] = 0;
	return nbmots;
}

/* lit une commande au clavier et la decoupe en champs 
entrees :
- argmax : nombre max de champs attendus
- argv[] : tableau de pointeurs qui seront connectes aux differents champs de la commande
- resultat : nombre de champs trouves
*/
int read_cmd(int argmax, char *argv[]){
	
	char *buf = (char *) malloc(MAX_CMD_SIZE * sizeof(char));
	size_t l;
	int nbmots=0;

	if (fgets(buf, MAX_CMD_SIZE, stdin) != NULL) {
	   l = strlen(buf);
	   if (l > 0) {
	       if (buf[l-1] == '\n') {
		  l--;
		  buf[l] = 0;
		  nbmots=cut_cmd(buf, argmax, argv);
		}
	   	else printf("commande trop longue\n");
	   }
	}
	free(buf);
	return nbmots;
}
/* Libere la memoire occupee par les differents champs d'une commande.
entrees : 
- argc : nombre de champs de la commande
- argv[] : tableau de pointeurs sur les differents champs
*/
void free_cmd(int argc, char *argv[]){

	int i;
	for (i=0; i<argc; i++) {
		free(argv[i]);
		argv[i]=NULL;
	}
	return;
}



