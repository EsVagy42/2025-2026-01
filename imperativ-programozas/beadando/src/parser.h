#ifndef PARSER_H
#define PARSER_H

struct letter {
  int width, height;
  char data[];
};

struct alphabet {
  struct letter *(letters[26]);
  int height;
};

typedef struct letter *letter_t;
typedef struct alphabet *alphabet_t;

char *get_letter_index(letter_t l, int x, int y);
alphabet_t alphabet_from(char *string);
void alphabet_free(alphabet_t a);

#endif
