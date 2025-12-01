#include "parser.h"
#include "string_vector.h"

int get_index(char c) { return c - 'a'; }
int valid_character(char c) { return c >= 'a' && c <= 'z'; }

string_vector_t draw_ascii_art(char *string, alphabet_t alphabet) {
  string_vector_t s = string_vector_new();
  for (int i = 0; i < alphabet->height; i++) {
    for (char *c = string; *c != '\0'; c++) {
      if (!valid_character(*c)) {
        continue;
      }
      letter_t l = alphabet->letters[get_index(*c)];
      for (int j = 0; j < l->width; j++) {
        string_vector_push_back(s, *get_letter_index(l, j, i));
      }
    }
    string_vector_push_back(s, '\n');
  }
  return s;
}
