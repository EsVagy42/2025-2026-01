#ifndef ALPHABET_H
#define ALPHABET_H

#include "dyn_str.h"
typedef struct letter {
  int width, height;
  char *data;
} letter;

letter letter_from(char *c, int width, int height);

void letter_free(letter *l);

char *letter_get(letter *l, int x, int y);

typedef struct alphabet {
  letter letters[26];
  int height;
} alphabet;

alphabet alphabet_from(char *c);

void alphabet_free(alphabet *abc);

letter *alphabet_get_letter(alphabet *abc, char l);

dyn_str alphabet_draw(alphabet *abc, char *s);

#endif
