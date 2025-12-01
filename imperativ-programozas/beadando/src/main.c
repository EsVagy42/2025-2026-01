#include "drawer.h"
#include "parser.h"
#include "string_vector.h"
#include <stdio.h>

int main() {
  FILE *alphabet_file = fopen("ascii_input.txt", "r");
  string_vector_t alphabet_string = string_vector_new();
  char next;
  while ((next = fgetc(alphabet_file)) != EOF) {
    string_vector_push_back(alphabet_string, next);
  }
  fclose(alphabet_file);
  alphabet_t alphabet = alphabet_from(string_vector_get(alphabet_string));

  string_vector_t s = draw_ascii_art("cicca", alphabet);
}
