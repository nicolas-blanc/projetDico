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

// A expliquer dans le rapport
void set_charnum(maillon_t * maillon, int carac, int lettre) {
	uint32_t masque_reset = 0x0000001f;
	uint32_t masque_lettre = 0x00000000;

	// Décalage coorespondant à la place du caractère
	lettre = (abs(lettre - 5)) * 5;

	// Création du masque qui permet de mettre à 0 l'emplacement du caractère
	masque_reset = ~(masque_reset << lettre);

	// Création du masque pour mettre la lettre dans le maillon
	masque_lettre = (~(masque_lettre + ~c)) << lettre;

	// Application des masques sur la maillon
	*maillon.lettres = (*maillon.lettres & masque_reset) | masque_lettre;
}

int get_charnum(maillon_t maillon, int lettre) {
	uint32_t masque_lettre2 = 0x0000001f;
	uint32_t res = 0x00000000;

	lettre = (abs(lettre - 5)) * 5;

	masque_lettre2 = masque_lettre2 << lettre;

	// Décalage dans l'autre sens pour récuperer la valeur exacte
	res = (maillon & masque_lettre) >> lettre;

	return res;
}






int compare_maillons(maillon_t maillon1, maillon_t maillon2) {
	bool fin = true;
	int res = 0;

	int i = 0;

	char * mot1 = maillon_to_char(maillon1);
	char * mot2 = maillon_to_char(maillon2);

	while(fin) {
		if (mot1[i] == '\0' || mot2[i] == '\0') {
			fin = false;
			if (mot1[i] == '\0')
				res -= 1;
			if (mot2[i] == '\0')
				res += 1;
		} else {
			if (mot1[i] != mot2[i]) {
				fin = false;
				if (mot1[i] < mot2[i])
					res = -1;
				else
					res = 1;
			}
		}
		i++;
	}

	return res;
}

int compare_mots(mot_t mot1, mot_t mot2) {
	return compare_maillons(mot1.tete_mot, mot2.tete_mot);
}