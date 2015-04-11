#include <stdio.h>
#include <stdlib.h>
#include "read_word.h"
#include "dico.h"

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

	int i=0;
	dico_t * dicotest =  (dico_t*)malloc(sizeof(dico_t));
	dicotest->suivant=NULL;
	dicotest->mot=NULL;

if (dicotest!=NULL)

	while(!feof(mon_fichier)){
		i=0;
		char * word = next_word(mon_fichier,&ligne,&colonne);
		while(word[i]!='\0'){
			i++;
		}
		mot_t* mot =(mot_t*)malloc(sizeof(mot_t));
		creation_mot(word,ligne,colonne,mot);
		affiche_mot(mot);
		dicotest=insertion_dictionnaire(dicotest,mot);
	}

	affiche_dico(dicotest);
	fclose(mon_fichier);

  return 0;
}
