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

	dico_t * dico =  nouveau_dictionnaire();
	mot_t* mot;

if (dico != NULL)

	while(!feof(mon_fichier)){
		// On lit une chaine de caractère dans le fichier
		char * word = next_word(mon_fichier,&ligne,&colonne);

		// on créé un nouveau mot à partir de la chaine de caractère
		mot = creation_mot(word,ligne,colonne);
		// affiche_mot(mot);
		// On insère ce mot dans le dictionnaire
		dico = insertion_dictionnaire(dico,mot);
	}

	affiche_dico(dico);
	fclose(mon_fichier);

  return 0;
}
