#include <stdlib.h>

#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

// Type pour les emplacements du mots dans le texte, un pour chaque emplacement
// Indique la ligne et la colonne d'apparition du mot auquel est lié l'emplacement
// empl_suiv indique l'emplacement de la prochaine apparition de ce mot
typedef struct emplacement_t emplacement_t;
struct emplacement_t
{
	unsigned int ligne;
	unsigned int colonne;

	emplacement_t * empl_suiv;
};

// Créer un nouvel emplacement initialisé à l pour ligne et c pour colonne
emplacement_t * initialise_emplacement(unsigned int l, unsigned int c);

// Ajoute un élèment de type emplacement à la suite de emp, avec pour valeurs ligne et colonne
// Pour ajouter un nouvel emplacement sur un mot, voir la fonction nouvel_emplacement(...) dans mot.h
emplacement_t * ajoute_emplacement(emplacement_t* emp, int ligne, int colonne);

#endif /* EMPLACEMENT_H */
