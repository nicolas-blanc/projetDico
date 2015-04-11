#include "dico.h"

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



uint32_t char_to_num(char carac) {
	return carac - 'a' + 1;
}

char num_to_char(uint32_t code) {
	return code + 'a' - 1;
}

// A expliquer dans le rapport
void set_charnum(maillon_t* maillon,  uint32_t carac, int lettre) {
	uint32_t masque_reset = 0x0000001f;
	uint32_t masque_lettre = 0x00000000;

	// Décalage coorespondant à la place du caractère
	lettre = (abs(lettre - 5)) * 5;

	// Création du masque qui permet de mettre à 0 l'emplacement du caractère
	masque_reset = ~(masque_reset << lettre);

	// Création du masque pour mettre la lettre dans le maillon
	masque_lettre = (~(masque_lettre + ~carac)) << lettre;

	// Application des masques sur la maillon
	maillon->lettres = (maillon->lettres & masque_reset) | masque_lettre;
}

uint32_t get_charnum(maillon_t maillon, int lettre) {
	uint32_t masque_lettre = 0x0000001f;	
	uint32_t res = 0x00000000;

	lettre = (abs(lettre - 5)) * 5;

	masque_lettre = masque_lettre << lettre;

	// Décalage dans l'autre sens pour récuperer la valeur exacte
	res = (maillon.lettres & masque_lettre) >> lettre;

	return res;
}

//Fonction retournant le nombre de lettre d'une liste de maillon
int nb_lettres_maillon(maillon_t* maillons){
	maillon_t* mail_temp = maillons;
	int compt=0;

	while((mail_temp != NULL) && (get_charnum(*mail_temp,(compt%6))!= 0)){
		//printf("Mon modulo:%d\n",compt%6);
		if ((compt>=6) && (compt%6 ==0)){
			mail_temp=mail_temp->maillon_suiv;
		}
		if (mail_temp != NULL)
		{
			compt+=1;	
		}
	}

	//	printf("J'ai %d lettres.\n", compt);
	return compt;
}


//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t* maillon){
	int i;
	//printf("Je suis dans maillon to char.\n");
	int nblettres=nb_lettres_maillon(maillon);
	//printf("J'ai compté les lettres.%d\n",nblettres);
	char *chaine=(char *)malloc(sizeof(char)*(nblettres+1));

	maillon_t* mail_temp = maillon;

	for (i = 0; i < nblettres; ++i) {
		if ((i>=6) && (i%6==0)) {
			mail_temp = mail_temp->maillon_suiv;
			//printf("%08x\n", mail_temp->lettres);
		}
		//("%d\n",get_charnum(*mail_temp, i%6));
		chaine[i]=num_to_char(get_charnum(*mail_temp, i%6));
	}
	chaine[i+1]='\0';
	return chaine;
}

// Retourne un maillon vide
maillon_t * initialise_maillon() {
	maillon_t * maillon = (maillon_t*) malloc(sizeof(maillon_t));

	maillon->lettres = 0x00000000;
	maillon->maillon_suiv = NULL;

	return maillon;
}

void mot_to_maillon(char* caracs, int nblettres, maillon_t* first_maillon){
	int i;

	maillon_t* mail_temp = first_maillon;
	for (i = 0; i < nblettres; ++i) {
		if ((i>=6) && (i%6==0)) {	
			maillon_t * next = initialise_maillon();
			mail_temp->maillon_suiv=next;
			mail_temp=next;
		}

		set_charnum(mail_temp,char_to_num(caracs[i]),i%6);
	}
	
}

// Compte le nombre de lettre dans un tableau de char jusqu'au symbole de fin de chaine ('\')
int nbLettres(char * caracs) {
	int i = 0;

	if (caracs != NULL)
		while(caracs[i] != '\0')
			i++;

	return i;
}

// Retourne le dernier maillon d'une chaine de maillon
maillon_t * definir_queue(maillon_t * maillon) {
	maillon_t * temp = maillon;

	while(temp->maillon_suiv != NULL)
		temp = temp->maillon_suiv;

	return temp;
}

emplacement_t * initialise_emplacement(unsigned int l, unsigned int c) {
	emplacement_t * empl = (emplacement_t*) malloc(sizeof(emplacement_t));

	empl->ligne = l;
	empl->colonne = c;
	empl->empl_suiv = NULL;

	return empl;
}

void creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol, mot_t * mot) {
	maillon_t * maillon = initialise_maillon();
	emplacement_t * emp = initialise_emplacement(nblin, nbcol);

	mot_to_maillon(caracs, nbLettres(caracs), maillon);
	mot->tete_mot = maillon;
	mot->queue_mot = definir_queue(maillon);
	mot->tete_liste = emp;
	mot->queue_liste = emp;
}

void affiche_mot(mot_t * mot){
	maillon_t* tete = mot->tete_mot;
	emplacement_t * empl = mot->tete_liste;

	char * cmot = maillon_to_char(tete);
	printf("%s", cmot);
	printf(" -->");
	while(empl != NULL) {
		printf("  [%d/%d]", empl->ligne, empl->colonne);
		empl = empl->empl_suiv;
	}
	printf("\n");
}

void affiche_dico(dico_t* dico){
	dico_t* temp = dico;
	printf("Voici le contenu du dictionnaire:\n");
	while(temp != NULL){
		affiche_mot(temp->mot);
		temp = temp->suivant;
	}
}


// Fonction qui compare deux maillon et retourne un entier nul si ils sont égaux, négatif si le 1er maillon est plus petit que le 2e maillon, positif sinon
int compare_maillons(maillon_t * maillon1, maillon_t * maillon2) {
	int fin = 1;
	int res = 0;

	int i = 0;

	char * mot1 = maillon_to_char(maillon1);
	char * mot2 = maillon_to_char(maillon2);

	while(fin) {
		if (mot1[i] == '\0' || mot2[i] == '\0') {
			fin = 0;
			if (mot1[i] == '\0')
				res -= 1;
			if (mot2[i] == '\0')
				res += 1;
		} else {
			if (mot1[i] != mot2[i]) {
				fin = 0;
				res = mot1[i] - mot2[i];
			}
		}
		i++;
	}

	return res;
}

//Fonction de comparasion de mots
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

//Fonction réalisant une simple insertion en tête de liste.
dico_t* insere_tete(dico_t* dico, mot_t * mot){
	dico_t* d = (dico_t*)malloc(sizeof(dico_t));
	d->mot=mot;
	d->suivant = dico;
	return d;
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
			/*d_temp=insere_tete(d_temp,mot);
			if (pred != NULL)
			{
				printf("PAsser dans le test\n");
				pred->suivant=d_temp;
			}*/


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
