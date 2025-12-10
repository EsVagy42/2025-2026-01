#include "alphabet.h"
#include "dyn_str.h"
#include <stdlib.h>

letter letter_from(char *c, int width, int height) {
  letter l = {width, height, (char *)malloc(sizeof(char) * width * height)};
  char *dest = l.data;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      while (*c == '\n') {
        c++;
      }
      *dest = *c;
      dest++;
      c++;
    }
  }
  return l;
}

void letter_free(letter *l) {
  free(l->data);
  *l = (letter){0, 0, NULL};
};

char *letter_get(letter *l, int x, int y) { return l->data + y * l->width + x; }

char *new_line(char *c) {
  while (*c != '\n' && *c != '\0') {
    c++;
  }
  return ++c;
}

alphabet alphabet_from(char *c) {
  alphabet abc;
  abc.height = atoi(c);
  c = new_line(c);
  for (int i = 0; i < 26; i++) {
    abc.letters[i] = letter_from(c, new_line(c) - c - 1, abc.height);
    for (int j = 0; j < abc.height; j++) {
      c = new_line(c);
    }
  }
  return abc;
}

void alphabet_free(alphabet *abc) {
  for (int i = 0; i < 26; i++) {
    letter_free(&abc->letters[i]);
  }
  abc->height = 0;
}

letter *alphabet_get_letter(alphabet *abc, char l) {
  return abc->letters + l - 'a';
}

dyn_str alphabet_draw(alphabet *abc, char *s) {
  dyn_str out = dyn_str_new();
  for (int l = 0; l < abc->height; l++) {
    for (char *c = s; *c != '\0'; c++) {
      letter *let = alphabet_get_letter(abc, *c);
      char *letline = letter_get(let, 0, l);
      for (char *letc = letline; letc < letline + let->width; letc++) {
        dyn_str_push_back(&out, *letc);
      }
    }
    dyn_str_push_back(&out, '\n');
  }
  return out;
}
