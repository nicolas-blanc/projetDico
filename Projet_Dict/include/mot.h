#include <stdio.h>
#include "emplacement.h"
#include "maillon.h"

#ifndef MOT_H
#define MOT_H

// Type qui permet de stocker les mots dans la liste chainée
// tete_mot pointe sur le premier maillon d'un mot
// queue_mot pointe sur le dernier maillon de ce mot
// tete_liste pointe sur le 1er emplacement de ce mot dans le texte
// queue_liste pointe sur le dernier emplacement de ce mot dans le texte
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

// Créer un nouveau mot à partir d'une chaine de caractères et de ligne et la colonne de la 1ère apparition de ce mot
// Retourne l'adresse du mot créé
mot_t * creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol);

// Affiche un élèment de type mot_t (Affiche un mot) :
// "mot" -> [l1/c1] [l2/c2]
void affiche_mot(mot_t * mot);

// Fonction de comparaison de deux mots
// Si mot1 == mot2 -> 0
// Si mot1 < mot2 -> -1
// Si mot1 > mot2 -> 1
int compare_mots(mot_t* mot1, mot_t* mot2);

// Ajoute un nouvel emplacement [ligne/colonne] dans un mot donné
void nouvel_emplacement(mot_t * mot, int ligne, int colonne);

#endif /* MOT_H */
