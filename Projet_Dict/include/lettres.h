#include <stdint.h>

#ifndef LETTRE_H
#define LETTRE_H

// Retourne le code défini dans le programme pour une lettre :
//	-> 'a' à pour code 1
//	-> 'b' à pour code 2
//	-> ...
//	-> 'z' à pour code 26
uint32_t char_to_num(char carac);

// retourne un caractère en fonction du code défini pour le programme -> Voir plus haut
char num_to_char(uint32_t code);

#endif /* LETTRE_H */