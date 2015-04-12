#include "../include/lettres.h"

// Retourne le code défini dans le programme pour une lettre
uint32_t char_to_num(char carac) {
	return carac - 'a' + 1;
}

// retourne un caractère en fonction du code défini pour le programme -> Voir plus haut
char num_to_char(uint32_t code) {
	return code + 'a' - 1;
}