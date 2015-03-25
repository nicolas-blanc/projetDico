#include <stdio.h>
#include <stdlib.h>
#include "read_word.h"

int main(int argc, char **argv) {

	FILE * mon_fichier = NULL;
	printf("%s\n",argv[0]);
	printf("%s\n",argv[1]);
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
	while(!feof(mon_fichier)){
		word = next_word(mon_fichier,&ligne,&colonne);
		printf("%s\n",word);
	}

	fclose(mon_fichier);
  return 0;
}
