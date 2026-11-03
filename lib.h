#ifndef LEARN_C_LIB_H
#define LEARN_C_LIB_H
#include "exercises.h"
#include <stddef.h>

/* Put declarations for your reusable helpers here. Include this file in lib.c
 * and in exercises that use those helpers. */
int my_isdigit(int c);
int my_isalpha(int c);
int my_isalnum(int c);
int my_isspace(int c);
int my_tolower(int c);
size_t my_strlen(const char *s);
char *my_strchr(const char *s, int c);
char *my_strcpy(char *destination, const char *source);
char *my_strncpy(char *destination, const char *source, size_t count);
void *my_memset(void *destination, int value, size_t count);
void *my_memcpy(void *destination, const void *source, size_t count);
size_t my_strspn(const char *s, const char *accepted);
size_t my_strcspn(const char *s, const char *rejected);
char *my_strdup(const char *s);
char *string_slice(const char *s, size_t start, size_t length);
int buffer_append(ByteBuffer *buffer, const void *data, size_t count);

#endif
