#include "../include/dico.h"

void affiche_dico(dico_t* dico){
	dico_t* temp = dico;
	printf("Voici le contenu du dictionnaire:\n");

	while(temp != NULL) {
		affiche_mot(temp->mot);
		temp = temp->suivant;
	}
}

dico_t * nouveau_dictionnaire() {
	// Un emplacement mémoire pour un nouveau dictionnaire est créé, puis les élèments de la structures sont initialisés à NULL
	dico_t * dico = (dico_t*) malloc(sizeof(dico_t));
	dico->suivant = NULL;
	dico->mot = NULL;

	return dico;
}

// Fonction réalisant une simple insertion en tête de liste.
dico_t * insere_tete(dico_t * dico, mot_t * mot) {
	dico_t * d_temp = nouveau_dictionnaire();
	d_temp->mot = mot;
	d_temp->suivant = dico;
	
	return d_temp;
}



//Fonction insérant un mot dans un dictionnaire
dico_t * insertion_dictionnaire(dico_t * dico, mot_t * mot) {
	
	dico_t * d_temp = dico;
	dico_t * pred = NULL;

	int compare = 0;

	// Si le dico est vide, on ajoute directement le mot dans le dictionnaire
	if (d_temp->mot != NULL) {
		// On avance le pointeur d_temp jusqu'à que, soit le pointeur arrive à la fin du dictionnaire, soit le mot est à son emplacement
		while(d_temp != NULL && compare_mots(d_temp->mot,mot) < 0) {
			pred = d_temp;
			d_temp = d_temp->suivant;
		}

		// Si le dictionnaire est NULL, on ajoute directement le mot à la fin du dictionnaire
		if (d_temp == NULL)
			pred->suivant = insere_tete(d_temp,mot);
		else {
			compare = compare_mots(d_temp->mot,mot);

			// Si le mot est présent dans le dictionnaire, on crée un nouvel emplacement dans le mot
			if (compare == 0)
				nouvel_emplacement(d_temp->mot,mot->tete_liste->ligne,mot->tete_liste->colonne);
			else
				// Permet de gérer les premiers mots du dictionnaire si on ne passe pas par la boucle
				if (pred == NULL && compare < 0 )
					d_temp->suivant = insere_tete(d_temp->suivant,mot);
				else if (pred == NULL)
					dico = insere_tete(dico,mot);
				else
					// On ajoute l'élèment dans le dictionnaire
					pred->suivant = insere_tete(d_temp,mot);
		}

	} else {
		dico->mot = mot;
		dico->suivant = NULL;
	}

	return dico;
}
