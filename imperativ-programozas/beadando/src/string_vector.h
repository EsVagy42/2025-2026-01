#ifndef STRING_VECTOR_H
#define STRING_VECTOR_H

#define STARTING_VECTOR_SIZE 32

typedef struct string_vector *string_vector_t;
string_vector_t string_vector_new();
char *string_vector_get(string_vector_t v);
void string_vector_push_back(string_vector_t v, char c);

#endif
