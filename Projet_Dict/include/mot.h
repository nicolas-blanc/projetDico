#include <stdio.h>
#include "emplacement.h"
#include "maillon.h"

#ifndef MOT_H
#define MOT_H

// Type qui permet de stocker les mots dans la liste chainée
typedef struct mot_t mot_t;
struct mot_t
{
	maillon_t * tete_mot;
	maillon_t * queue_mot;

	emplacement_t * tete_liste;
	emplacement_t * queue_liste;
};

// Compte le nombre de lettre dans un tableau de char jusqu'au symbole de fin de chaine ('\')
int nbLettres(char * caracs);

mot_t * creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol);

void affiche_mot(mot_t * mot);

//Fonction de comparaison de mots
//Si mot1 == mot2 -> 0
//Si mot1 < mot2 -> -1
//Si mot1 > mot2 -> 1
int compare_mots(mot_t* mot1, mot_t* mot2);

void nouvel_emplacement(mot_t * mot, int ligne, int colonne);
#endif /* MOT_H */
