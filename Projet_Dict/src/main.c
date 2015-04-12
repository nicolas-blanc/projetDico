#include <stdio.h>
#include <stdlib.h>

#include "../include/read_word.h"
#include "../include/dico.h"
#include "../include/mot.h"

int main(int argc, char **argv) {

	//On declare un fichier
	FILE * mon_fichier = NULL;

	//Si le nombre d'argument est trop grand, on 
	if (argc > 2)
	{
		printf("Trop d'argument!\n");
	}
	else if (argc == 2)
	{
		mon_fichier=fopen(argv[1],"r");
		if (mon_fichier==NULL)
		{
			printf("Impossible d'ouvrir le fichier.\n");
			return -1;
		}
	}
	else {
		mon_fichier=stdin;
	}

	unsigned int ligne;
	unsigned int colonne;

	dico_t * dicotest =  nouveau_dictionnaire();
	mot_t* mot;

if (dicotest != NULL)

	while(!feof(mon_fichier)){
		char * word = next_word(mon_fichier,&ligne,&colonne);
		printf("1\n");
		mot = creation_mot(word,ligne,colonne);
		printf("2\n");
		affiche_mot(mot);
		printf("3\n");
		dicotest = insertion_dictionnaire(dicotest,mot);
		printf("4\n");
	}

	affiche_dico(dicotest);
	fclose(mon_fichier);

  return 0;
}
