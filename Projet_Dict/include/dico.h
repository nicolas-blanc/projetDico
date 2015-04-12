#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "lettres.h"
#include "mot.h"

#ifndef DICO_H
#define DICO_H

// Type qui permet de définir la structure d'un dictionnaire
// Le pointeur mot pointe sur le mot 
// suivant pointe sur l'élèment suivant du dictionnaire
typedef struct dico_t dico_t;
struct dico_t
{
	mot_t * mot;

	dico_t* suivant;
};

// Fonction affichant le contenu du dictionnaire :
// "mot1" -> [l1/c1] [l2/c2]
// "mot2" -> [l/c]
// ...
// "motn" -> [l1/c1] [l2/c2] [l3/c3]
void affiche_dico(dico_t* dico);

// Créer un nouveau dictionnaire, et le met mot et suivant à NULL
dico_t * nouveau_dictionnaire();

// Insère un nouvel élèment de type mot dans le dictionnaire, met ce mot à son emplacement selon l'ordre lexicographique
dico_t * insere_tete(dico_t * dico, mot_t * mot);

// Fonction d'insertion d'un mot de type mot_t dans un dictionnaire
// Insère cette élèment à son emplacement selon l'ordre lexicographique
// Si le mode existe déjà dans le dictionnaire, un nouvel emplacement est rajouté à la suite des emplacements dans le mot
dico_t * insertion_dictionnaire(dico_t * dico, mot_t * mot);

#endif /* DICO_H */
