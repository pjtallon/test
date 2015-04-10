#ifndef PARSER_H
#define PARSER_H

// struct {
	
// };

void print_arguments(int ,char **);

#ifndef __LIRECMD
#define __LIRECMD

#define MAX_CMD_SIZE 1024  // Nombre max de caracteres
#define MAX_ARG 16	// Nombre max d'arguments

/*
lit une commande au clavier, s�pare les differents champs, les enregistre dans des chaines reservees dynamiquement, et enregistre leurs adresses dans le tableau argv passe en parametre. 
entrees :
- argmax : nombre max de champs attendus
- argv[] : tableau de pointeurs qui seront connectes aux differents champs de la commande
- resultat : nombre de champs trouves
Les caracteres > < | & sont isoles dans des champs separes meme losrqu'ils sont colles a d'autres mots
Ex : ccc <fic1 arg1|arg2 >fic2& est eclatee en 9 champs :
ccc < fic1 arg1 | arg2 > fic2 &
*/
int read_cmd(int argmax, char *argv[]);

/* Libere la memoire occupee par les differents champs d'une commande.
entrees : 
- argc : nombre de champs de la commande
- argv[] : tableau de pointeurs sur les differents champs
*/
void free_cmd(int argc, char *argv[]);

#endif



#endif
