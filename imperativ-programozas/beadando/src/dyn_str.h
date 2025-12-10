#ifndef DYN_STR_H
#define DYN_STR_H

#define STARTING_STR_SIZE 32

typedef struct dyn_str {
  int size;
  int length;
  char *str;
} dyn_str;

dyn_str dyn_str_new();

void dyn_str_free(dyn_str *s);

void dyn_str_push_back(dyn_str *s, char c);

char *dyn_str_string(dyn_str *s);

#endif
