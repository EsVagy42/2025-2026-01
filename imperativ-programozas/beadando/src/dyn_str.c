#include "dyn_str.h"
#include <stdlib.h>

dyn_str dyn_str_new() {
  return (dyn_str){STARTING_STR_SIZE, 0,
                   malloc(STARTING_STR_SIZE * sizeof(char))};
}

void dyn_str_free(dyn_str *s) {
  free(s->str);
  *s = (dyn_str){0, 0, NULL};
}

void dyn_str_push_back(dyn_str *s, char c) {
  s->str[s->length] = c;
  s->length++;
  if (s->length == s->size) {
    s->size *= 2;
    s->str = realloc(s->str, s->size);
  }
}

char *dyn_str_string(dyn_str *s) {
  s->str[s->length] = '\0';
  return s->str;
}
