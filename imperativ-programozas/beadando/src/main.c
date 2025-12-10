#include "alphabet.h"
#include "dyn_str.h"
#include <stdio.h>

int main() {
  FILE *f = fopen("ascii_input.txt", "r");
  dyn_str file_contents = dyn_str_new();
  char ch;
  while ((ch = fgetc(f)) != EOF) {
    dyn_str_push_back(&file_contents, ch);
  }

  alphabet abc = alphabet_from(dyn_str_string(&file_contents));
  dyn_str output = alphabet_draw(&abc, "Hello, world!");
  printf("%s\n", dyn_str_string(&output));

  fclose(f);
}
