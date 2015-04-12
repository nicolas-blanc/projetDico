#include "lettres.h"
#include <stdlib.h>
#include <math.h>

// Type pour les maillons, si le mot est composé de plus de 6 lettres, un nouveau est créé
typedef struct maillon_t maillon_t;
struct maillon_t {
	uint32_t lettres;

	maillon_t * maillon_suiv;
};


// A expliquer dans le rapport
void set_charnum(maillon_t* maillon,  uint32_t carac, int lettre);

uint32_t get_charnum(maillon_t maillon, int lettre);

//Fonction retournant le nombre de lettre d'une liste de maillon
int nb_lettres_maillon(maillon_t* maillons);

// Retourne le dernier maillon d'une chaine de maillon
maillon_t * definir_queue(maillon_t * maillon);

//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t* maillon);

// Retourne un maillon vide
maillon_t * initialise_maillon();

void mot_to_maillon(char* caracs, int nblettres, maillon_t* first_maillon);

// Fonction qui compare deux maillon et retourne un entier nul si ils sont égaux, négatif si le 1er maillon est plus petit que le 2e maillon, positif sinon
int compare_maillons(maillon_t * maillon1, maillon_t * maillon2);