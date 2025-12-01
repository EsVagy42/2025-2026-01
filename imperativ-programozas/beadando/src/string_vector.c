#include "string_vector.h"
#include <stdlib.h>

struct string_vector {
  int size;
  int length;
  char data[];
};
typedef struct string_vector string_vector;

string_vector *string_vector_new() {
  string_vector *v =
      malloc(sizeof(string_vector) + sizeof(char) * STARTING_VECTOR_SIZE);
  v->size = STARTING_VECTOR_SIZE;
  v->data[0] = '\0';
  v->length = 0;
  return v;
}

char *string_vector_get(string_vector *v) { return v->data; }

void string_vector_push_back(string_vector *v, char c) {
  if (v->size == v->length + 1) {
    v = realloc(v, v->size * 2);
    v->size *= 2;
  }
  v->data[v->length] = c;
  v->length++;
}
