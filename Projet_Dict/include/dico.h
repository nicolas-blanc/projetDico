#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "lettres.h"
#include "mot.h"

typedef struct dico_t dico_t;
struct dico_t
{
	mot_t * mot;
	dico_t* suivant;
};

//Fonction affichant le contenu du dictionnaire
void affiche_dico(dico_t* dico);

dico_t* insere_tete(dico_t * dico, mot_t * mot);

// Fonction d'insertion d'un mot de type mot_t dans un dictionnaire
// Insère le mot à la fin de la chaine, sans rangement alphabétique et avec duplication
dico_t* insertion_dictionnaire(dico_t * dico, mot_t * mot);