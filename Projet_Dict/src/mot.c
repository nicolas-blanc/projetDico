#include "../include/mot.h"


// Compte le nombre de lettre dans un tableau de char jusqu'au symbole de fin de chaine ('\')
int nbLettres(char * caracs) {
	int i = 0;

	if (caracs != NULL)
		while(caracs[i] != '\0')
			i++;

	return i;
}

mot_t * creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol) {
	mot_t * mot = (mot_t*) malloc(sizeof(mot_t));

	maillon_t * maillon = initialise_maillon();
	emplacement_t * emp = initialise_emplacement(nblin, nbcol);

	mot_to_maillon(caracs, nbLettres(caracs), maillon);
	mot->tete_mot = maillon;
	mot->queue_mot = definir_queue(maillon);
	mot->tete_liste = emp;
	mot->queue_liste = emp;

	return mot;
}

void affiche_mot(mot_t * mot){
	maillon_t* tete = mot->tete_mot;
	emplacement_t * empl = mot->tete_liste;

	char * cmot = maillon_to_char(tete);
	printf("%s (%08X)  -->", cmot, tete->lettres);
	while(empl != NULL) {
		printf("  [%d/%d]", empl->ligne, empl->colonne);
		empl = empl->empl_suiv;
	}
	printf("\n");
}

//Fonction de comparaison de mots
//Si mot1 == mot2 -> 0
//Si mot1 < mot2 -> -1
//Si mot1 > mot2 -> 1
int compare_mots(mot_t* mot1, mot_t* mot2) {

	maillon_t* m1 = mot1->tete_mot;
	maillon_t* m2 = mot2->tete_mot;
	int compare = 2;

	while (compare == 2) {
		if (m1->lettres < m2->lettres) {
			compare = -1;
		} else if (m1->lettres > m2->lettres) {
			compare = 1;
		} else {
			m1 = m1->maillon_suiv;
			m2 = m2->maillon_suiv;
			if (m1 == NULL && m2 == NULL) {
				compare = 0;
			} else if (m1 != NULL && m2 == NULL) {
				compare = -1;
			} else if (m1 == NULL && m2 != NULL) {
				compare = 1;
			}
		}
	}
	return compare;
}

void nouvel_emplacement(mot_t * mot, int ligne, int colonne) {
	mot->queue_liste = ajoute_emplacement(mot->queue_liste,ligne,colonne);
}