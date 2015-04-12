#include <stdlib.h>

#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

// Type pour les emplacements du mots dans le texte, un pour chaque emplacement
typedef struct emplacement_t emplacement_t;
struct emplacement_t
{
	unsigned int ligne;
	unsigned int colonne;

	emplacement_t * empl_suiv;
};

emplacement_t * initialise_emplacement(unsigned int l, unsigned int c);

emplacement_t * ajoute_emplacement(emplacement_t* emp, int ligne, int colonne);

#endif /* EMPLACEMENT_H */
