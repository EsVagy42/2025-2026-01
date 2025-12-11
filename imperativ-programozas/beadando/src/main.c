#include "alphabet.h"
#include "dyn_str.h"
#include <stdio.h>

void draw_str(char *s, alphabet *abc) {
  dyn_str ascii_art = alphabet_draw(abc, s);
  printf("%s", dyn_str_string(&ascii_art));
  dyn_str_free(&ascii_art);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <alphabet file>\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Couldn't open file\n");
    return 2;
  }
  dyn_str file_contents = dyn_str_new();
  char ch;
  while ((ch = fgetc(f)) != EOF) {
    dyn_str_push_back(&file_contents, ch);
  }

  alphabet abc = alphabet_from(dyn_str_string(&file_contents));

  dyn_str input = dyn_str_new();
  char ich;
  while ((ich = getchar()) != EOF) {
    if (ich == '\n') {
      draw_str(dyn_str_string(&input), &abc);
      dyn_str_free(&input);
      input = dyn_str_new();
    } else {
      dyn_str_push_back(&input, ich);
    }
  }

  dyn_str_free(&input);
  alphabet_free(&abc);
  dyn_str_free(&file_contents);
  fclose(f);
}
