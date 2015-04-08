#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Type pour les maillons, si le mot est composé de plus de 6 lettres, un nouveau est créé
typedef struct maillon_t maillon_t;
struct maillon_t {
	uint32_t lettres;

	maillon_t * maillon_suiv;
};

// Type pour les emplacements du mots dans le texte, un pour chaque emplacement
typedef struct emplacement_t emplacement_t;
struct emplacement_t
{
	unsigned int ligne;
	unsigned int colonne;

	emplacement_t * empl_suiv;
};

// Type qui permet de stocker les mots dans la liste chainée
typedef struct mot_t mot_t;
struct mot_t
{
	maillon_t * tete_mot;
	maillon_t * queue_mot;

	emplacement_t * tete_liste;
	emplacement_t * queue_liste;

	mot_t * mot_suiv;
};

// Fonction de correspondance entre un caractère et son code
uint32_t char_to_num(char carac);
char num_to_char(uint32_t code);
// Fonction de modification et consultation de la kieme lettre sur un maillon donné (0 <= k <= 5)
void set_charnum(maillon_t* maillon, uint32_t carac, int lettre);
uint32_t get_charnum(maillon_t maillon, int lettre);

// Fonction de conversion d'une chaine de caractère en liste de maillons.
void mot_to_maillon(char * caracs, int nblettres, maillon_t * first_maillon);

// Fonction de création d'un élèment de type mot_t
void creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol, mot_t * mot);

// Fonction d'affichage d'un mot de type mot_t
void affiche_mot(mot_t * mot);

// Fonction de comparaison de deux mot_t
// retourne 0 si les deux sont identiques, un entier négatif si le premier est alphabétiquement plus petit, un entier positif sinon
int compare_mots(mot_t mot1, mot_t mot2);

// Fonction d'insertion d'un mot de type mot_t dans un dictionnaire
// Insère le mot à la fin de la chaine, sans rangement alphabétique et avec duplication
void insertion_dictionnaire(mot_t * dico, mot_t * mot);

// Fonction d'affichage du dictionnaire complet
void affiche_dictionnaire(mot_t * dico);