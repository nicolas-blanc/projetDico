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

void set_charnum(maillon_t maillon, int carac, int lettre) {
	// Hex : FFFF FFE0
	uint32_t masque_reset = 0xffffffe0
}

int get_charnum(maillon_t maillon, int lettre) {

}

//Fonction retournant le nombre de lettre d'une liste de maillon
int nb_lettres_maillon(maillon_t* maillons){
	maillon_t mail_temp = *maillons;
	int i = 0;
	while(get_charnum(mail_temp,(i%6))!= 0){
		i++;
		if (i%6==0)
		{
			mail_temp=mail_temp.maillon_suiv;
		}
	}
	return i;
}

// Fonction de conversion d'une chaine de caractère en liste de maillons.
void mot_to_maillon(char* caracs,int nblettres, maillon_t* first_maillon){
	int i;
	int nbmaillons;
	maillon_t mail_temp;
	mail_temp = first_maillon;

	for (i = 0; i < nblettres; ++i)
	{
		if ((i>=6) && (i%6==0))
		{
			mail_temp = mail_temp.maillon_suiv;
		}
		set_charnum(mail_temp,char_to_num(caracs[i]),i);
	}
	return first_maillon;
}

//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t maillon){
	int i;
	int nblettres=nb_lettres_maillon(maillon);
	char *chaine=(char *)malloc(sizeof(char)*(nblettres+1));

	maillon_t mail_temp = maillon;

	for (i = 0; i < nblettres; ++i)
	{
		if ((i>=6) && (i%6==0)
		{
			mail_temp = mail_temp.maillon_suiv;
		}
		chaine[i]=char_to_num(get_charnum(mail_temp, i));
	}
	chaine[i+1]='\0';
	return chaine;
}
