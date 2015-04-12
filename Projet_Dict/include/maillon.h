#include "lettres.h"
#include <stdlib.h>
#include <math.h>

#ifndef MAILLON_H
#define MAILLON_H

// Type pour les maillons, si le mot est composé de plus de 6 lettres, un nouveau est créé
// Le mot est stocké dans lettres selon un codage sur 5 bit défini par la fonction char_to_num dans lettres.h
// Composition d'un  maillon sur 32 bits :
// [32<-30]			[29<-24]		[24<-20]		[19<-15]		[14<-10]		[9<-5]			[4<-0]
//  -> Inutilisé	 -> Lettres 0	 -> Lettres 1	 -> Lettres 2 	 -> Lettres 3 	 -> Lettres 4 	 -> Lettres 5
// maillon_suiv pointe sur la suite du mot, si ce mot fait plus de 6 lettres
typedef struct maillon_t maillon_t;
struct maillon_t
{
	uint32_t lettres;

	maillon_t * maillon_suiv;
};


// Met à jour une lettre à partir de son emplacement dans le maillon
void set_charnum(maillon_t* maillon,  uint32_t carac, int lettre);

// Retourne le code d'une lettre selon position de cette lettre dans le maillon
uint32_t get_charnum(maillon_t maillon, int lettre);

//Fonction retournant le nombre de lettre d'une liste de maillon
int nb_lettres_maillon(maillon_t* maillons);

// Retourne le dernier maillon d'une chaine de maillon
maillon_t * definir_queue(maillon_t * maillon);

//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t* maillon);

// Retourne un maillon vide
maillon_t * initialise_maillon();

// Permet de créer une liste de maillon à partir d'une chaine de caractère
void mot_to_maillon(char* caracs, int nblettres, maillon_t* first_maillon);

// Fonction qui compare deux maillon et retourne un entier nul si ils sont égaux, négatif si le 1er maillon est plus petit que le 2e maillon, positif sinon
int compare_maillons(maillon_t * maillon1, maillon_t * maillon2);

#endif /* MAILLON_H */
