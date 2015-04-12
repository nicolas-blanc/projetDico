#include "../include/dico.h"

/*
// Fonction de correspondance entre un caractère et son code
uint32_t char_to_num(char carac);
char num_to_char(uint32_t code);

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

void affiche_dico(dico_t* dico){
	dico_t* temp = dico;
	printf("Voici le contenu du dictionnaire:\n");
	while(temp != NULL){
		affiche_mot(temp->mot);
		temp = temp->suivant;
	}
}

//Fonction réalisant une simple insertion en tête de liste. 
dico_t* insere_tete(dico_t* dico, mot_t * mot){
	dico_t* d = (dico_t*)malloc(sizeof(dico_t));
	d->mot=mot;
	d->suivant = dico;
	return d;
}

//Fonction insérant un mot dans un dictionnaire
dico_t* insertion_dictionnaire(dico_t * dico, mot_t * mot) {
	
	dico_t* d_temp = dico;
	dico_t* pred = NULL;

	if (d_temp->mot != NULL)
	{
		//Le dico est pas vide, on cherche l'emplacement du mot.
		while(compare_mots(d_temp->mot,mot) < 0 && d_temp->suivant != NULL)
		{	
			printf("WOUI\n");
			pred = d_temp;
			d_temp = d_temp->suivant;
		}

		//Le mot courant est plus grand que le mot à insérer.
		if (compare_mots(d_temp->mot,mot) > 0)
		{
			printf("Plus grand\n");
			pred = d_temp->suivant;
			d_temp->suivant = (dico_t*)malloc(sizeof(dico_t));
			if (d_temp->suivant == NULL) {
				fprintf(stderr, "Allocation impossible (ajout_dico).\n");
				exit(EXIT_FAILURE);
			}
			d_temp->suivant->mot = mot;
			d_temp->suivant->suivant = pred;


		}
		else if (compare_mots(d_temp->mot,mot) < 0)
		{
			printf("Plus petit\n");
			d_temp->suivant=(dico_t*)malloc(sizeof(dico_t));
			d_temp->suivant->mot = mot;
			d_temp->suivant->suivant=NULL;
		}
		else {
			printf("Deja la\n");
			ajoute_emplacement(d_temp->mot->tete_liste,mot->tete_liste->ligne,mot->tete_liste->colonne);
		}

	}
	else {
		// Si le dico est vide
		// On ajoute le mot
		dico->mot = mot;
		dico->suivant = NULL;
	}

	return dico;
}
