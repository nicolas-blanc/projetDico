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

	char *word=(char *)malloc(sizeof(char)*26);

	int i=0;
	maillon_t mail_temp;
	while(!feof(mon_fichier)){
		word = next_word(mon_fichier,&ligne,&colonne);
		while(word[i]!='\0'){
			i++;
		}
		mot_to_maillon(word,i-1,&mail_temp);
	}

	fclose(mon_fichier);


  return 0;
}
