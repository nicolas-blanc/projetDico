#include "dico.h"

/*
// Fonction de correspondance entre un caractère et son code
uint8_t char_to_num(char carac);
char num_to_char(uint8_t code);

// Fonction de modification et consultation de la kieme lettre sur un maillon donné (0 <= k <= 5)
void set_charnum(maillon_t maillon, char carac, int lettre);
char get_charnum(maillon_t maillon, int lettre);

// Fonction de conversions du chaine de caractère en liste de maillons, et une liste de maillons en chaine de caractère

// Fonction de création d'un élèment de type mot_t

// Fonction d'affichage d'un mot de type mot_t

// Fonction de comparaison de deux mot_t
// retourne 0 si les deux sont identiques, un entier négatif si le premier est alphabétiquement plus petit, un entier positif sinon
int compare_mots(mot_t * mot1, mot_t * mot2);

// Fonction d'insertion d'un mot de type mot_t dans un dictionnaire
// Insère le mot à la fin de la chaine, sans rangement alphabétique et avec duplication
void insertion_dictionnaire(mot_t * dico, mot_t * mot);

// Fonction d'affichagedu dictionnaire complet
void affiche_dictionnaire(mot_t * dico);
*/



uint8_t char_to_num(char carac) {
	return carac - 'a' + 1;
}

char num_to_char(uint8_t code) {
	return code + 'a' - 1;
}

void set_charnum(maillon_t maillon, char carac, int lettre) {
	// Hex : FFFF FFE0
	uint32_t masque_reset = 4294967264
}

char get_charnum(maillon_t maillon, int lettre) {
}


