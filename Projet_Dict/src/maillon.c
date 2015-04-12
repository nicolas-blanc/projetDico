#include "../include/maillon.h"


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
		if ((compt>=6) && (compt%6 ==0))
			mail_temp=mail_temp->maillon_suiv;

		if (mail_temp != NULL)
			compt+=1;
	}

	return compt;
}

// Retourne le dernier maillon d'une chaine de maillon
maillon_t * definir_queue(maillon_t * maillon) {
	maillon_t * temp = maillon;

	while(temp->maillon_suiv != NULL)
		temp = temp->maillon_suiv;

	return temp;
}

//Fonction de conversion d'une liste de maillons en une chaine de caractère
char* maillon_to_char(maillon_t* maillon){
	int i;

	int nblettres = nb_lettres_maillon(maillon);

	char *chaine = (char *)malloc(sizeof(char)*(nblettres+1));

	maillon_t* mail_temp = maillon;

	for (i = 0; i < nblettres; ++i) {
		if ((i>=6) && (i%6==0))
			mail_temp = mail_temp->maillon_suiv;

		chaine[i] = num_to_char(get_charnum(*mail_temp, i%6));
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
