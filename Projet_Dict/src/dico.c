#include "../include/dico.h"

void affiche_dico(dico_t* dico){
	dico_t* temp = dico;
	printf("Voici le contenu du dictionnaire:\n");
	while(temp != NULL){
		affiche_mot(temp->mot);
		temp = temp->suivant;
	}
}

dico_t * nouveau_dictionnaire() {
	dico_t * dico = (dico_t*) malloc(sizeof(dico_t));
	dico->suivant = NULL;
	dico->mot = NULL;

	return dico;
}

//Fonction réalisant une simple insertion en tête de liste. 
dico_t * insere_tete(dico_t * dico, mot_t * mot) {
	printf("7.1\n");
	dico_t * d_temp = nouveau_dictionnaire();
	d_temp->mot = mot;
	d_temp->suivant = dico;
	printf("7.8\n");
	return d_temp;
}



//Fonction insérant un mot dans un dictionnaire
dico_t * insertion_dictionnaire(dico_t * dico, mot_t * mot) {
	
	dico_t * d_temp = dico;
	dico_t * pred = NULL;

	int compare = 0;

//Si mot1 == mot2 -> 0
//Si mot1 < mot2 -> -1
//Si mot1 > mot2 -> 1

	//*
	if (d_temp->mot != NULL) {
		//printf("4.5 : %d\n",compare_mots(d_temp->mot,mot));
//		while(d_temp != NULL && compare_mots(d_temp->mot,mot) < 0)
		while(compare_mots(d_temp->mot,mot) < 0 && d_temp->suivant != NULL)
		{
			printf("5 : %d\n",compare_mots(d_temp->mot,mot));
			pred = d_temp;
			d_temp = d_temp->suivant;
		}

		printf("6 : ");
		printf("%d\n", compare_mots(d_temp->mot,mot));

		compare = compare_mots(d_temp->mot,mot);

		printf("9\n");

		if (compare == 0) {			
			printf("8\n");
			nouvel_emplacement(d_temp->mot,mot->tete_liste->ligne,mot->tete_liste->colonne);
		} else {
			if (pred == NULL && compare < 0 ) {
				dico->suivant = insere_tete(dico->suivant,mot);
			} else if (pred == NULL) {
				dico = insere_tete(dico,mot);
			} else {
				pred->suivant = insere_tete(d_temp,mot);
				printf("7\n");
			}
		}

	} else {
		// Si le dico est vide on ajoute le mot
		dico->mot = mot;
		dico->suivant = NULL;
	}
	//*/
	

	/*
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
	//*/
	affiche_dico(dico);
	return dico;
}
