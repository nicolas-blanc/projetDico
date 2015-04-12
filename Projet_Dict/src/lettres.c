#include "../include/lettres.h"

uint32_t char_to_num(char carac) {
	return carac - 'a' + 1;
}

char num_to_char(uint32_t code) {
	return code + 'a' - 1;
}