#include "../include/emplacement.h"

emplacement_t * initialise_emplacement(unsigned int l, unsigned int c) {
	emplacement_t * empl = (emplacement_t*) malloc(sizeof(emplacement_t));

	empl->ligne = l;
	empl->colonne = c;
	empl->empl_suiv = NULL;

	return empl;
}


void ajoute_emplacement(emplacement_t* emp, int ligne, int colonne){
	emplacement_t* e_temp = emp;

	while(e_temp->empl_suiv !=NULL){
		e_temp=e_temp-> empl_suiv;
	}

	e_temp->empl_suiv=(emplacement_t*)malloc(sizeof(emplacement_t));

	e_temp=e_temp-> empl_suiv;
	e_temp->ligne=ligne;
	e_temp->colonne=colonne;
	e_temp->empl_suiv=NULL;
}