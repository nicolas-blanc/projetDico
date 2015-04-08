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
	int i = 5;


	while(i==5){
	i=0;

	if (mail_temp->maillon_suiv!=NULL)
		mail_temp=mail_temp->maillon_suiv;

	for (i = 0; i < 6; ++i)
		if (get_charnum(*mail_temp,(i))!= 0)
			compt+=1;
	}

	return compt;
}


//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t* maillon){
	int i;
	printf("Je suis dans maillon to char.\n");
	int nblettres=nb_lettres_maillon(maillon);
	printf("J'ai compté les lettres.%d\n",nblettres);
	char *chaine=(char *)malloc(sizeof(char)*(nblettres+1));

	maillon_t* mail_temp = maillon;

	for (i = 0; i < nblettres; ++i) {
		if ((i>=6) && (i%6==0)) {
			mail_temp = mail_temp->maillon_suiv;
		}

		printf("%d\n",get_charnum(*mail_temp, i%6));
		chaine[i]=num_to_char(get_charnum(*mail_temp, i%6));
	}
	chaine[i+1]='\0';
	return chaine;
}

void mot_to_maillon(char* caracs, int nblettres, maillon_t* first_maillon){
	int i;

	maillon_t* mail_temp = first_maillon;

	for (i = 0; i < nblettres; ++i) {
		//printf("%d\n",i );
		if ((i>=6) && (i%6==0)) {	
			//printf("Je crée un new maillon.\n");
			maillon_t* next =(maillon_t*)malloc(sizeof(maillon_t));
			next->lettres=0;
			next->maillon_suiv=NULL;
			mail_temp->maillon_suiv=next;
			mail_temp=next;
		}

		set_charnum(mail_temp,char_to_num(caracs[i]),i);
	}
	
}

int nbLettres(char * caracs) {
	int i = 0;

	if (caracs != null)
		while(caracs[i] != '\0')
			i++;

	return i;
}

maillon_t * definir_queue(maillon_t * maillon) {
	maillon_t * temp = maillon;

	while(temp->maillon_suiv != null)
		temp = maillon_suiv;

	return temp;
}

mot_t creation_mot(char * caracs, unsigned int nblin, unsigned int nbcol) {
	maillon_t * maillon;
	emplacement_t emp = {nblin, nbcol, null};
	mot_t mot;

	mot_to_maillon(caracs, nbLettres(caracs), maillon);

	mot.tete_mot = maillon;
	mot.queue_mot = definir_queue(maillon);

	mot.tete_liste = &emp;
	mot.queue_liste = &emp;
}

// Fonction qui compare deux maillon et retourne un entier nul si ils sont égaux, négatif si le 1er maillon est plus petit que le 2e maillon, positif sinon
int compare_maillons(maillon_t maillon1, maillon_t maillon2) {
	int fin = 1;
	int res = 0;

	int i = 0;

	char * mot1 = maillon_to_char(&maillon1);
	char * mot2 = maillon_to_char(&maillon2);

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
				res = mot1[i] - mot2[i]
			}
		}
		i++;
	}

	return res;
}

int compare_mots(mot_t mot1, mot_t mot2) {
	return compare_maillons(mot1.tete_mot, mot2.tete_mot);
}

