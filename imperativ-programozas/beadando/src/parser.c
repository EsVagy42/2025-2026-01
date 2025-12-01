#include "parser.h"
#include <stdlib.h>
#include <string.h>

typedef struct letter letter;

int get_line_size(char *string) {
  int size = 0;
  while (string[size] != '\n' && string[size] != '\0') {
    size++;
  }
  return size;
}

char *get_letter_index(letter *l, int x, int y) {
  return &(l->data[y * l->width + x]);
}

letter *letter_from(char *string, int height) {
  letter tmpl = (letter){get_line_size(string), height};
  letter *l = malloc(sizeof(letter) + sizeof(char) * tmpl.width * tmpl.height);
  *l = tmpl;
  int row = 0;
  int col = 0;
  char *c = string;
  while (row < height) {
    if (*c == '\0') {
      break;
    }
    if (*c == '\n') {
      row++;
      col = 0;
      c++;
      continue;
    }
    *get_letter_index(l, col, row) = *c;
  }
  return l;
}

void letter_free(letter *l) { free(l); }

typedef struct alphabet alphabet;

alphabet *alphabet_from(char *string) {
  int first_size = get_line_size(string);
  char *num = malloc(sizeof(char) * (first_size + 1));
  memcpy(num, string, first_size);
  num[first_size] = '\0';
  int height = atoi(num);
  free(num);

  alphabet *a = malloc(sizeof(alphabet));
  a->height = height;
  int row = 1;
  int letter = 0;
  char *c = string;
  while (letter < 26) { // TODO: can it be made better
    while (row != 0) {
      if (*c == '\n') {
        row--;
      }
      c++;
    }
    a->letters[letter] = letter_from(c, height);
    letter++;
    row = height;
  }
  return a;
}

void alphabet_free(alphabet *a) {
  for (int i = 0; i < 26; i++) {
    letter_free(a->letters[i]);
  }
  free(a);
}
