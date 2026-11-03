#include "lib.h"
#include <stdlib.h>

/* Put your reusable implementations here. This file is linked into every
 * playground and test executable. Do not add a main function here. */
typedef int keep_translation_unit_nonempty;

int my_isdigit(int c) {
    return '0' <= c && c <= '9';
}

int my_isalpha(int c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int my_isspace(int c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

int my_tolower(int c) {
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return c;
}

size_t my_strlen(const char *s) {
    const char *const start = s;
    while (*s) ++s;
    return s - start;
}

char *my_strchr(const char *s, int c) {
    while (*s && *s != c) ++s;
    if (*s != c) return NULL;
    return (char *)s;
}

char *my_strcpy(char *destination, const char *source) {
    char *d = destination;
    while((*d++ = *source++));
    return destination;
}

char *my_strncpy(char *destination, const char *source, size_t count) {
    for (char *d = destination; count--; ++d) {
        *d = *source;
        if (*source) ++source;
    }
    return destination;
}

void *my_memset(void *destination, int value, size_t count) {
    unsigned char *d = destination;
    while (count--) *d++ = (unsigned char)value;
    return destination;
}

void *my_memcpy(void *destination, const void *source, size_t count) {
    unsigned char *d = destination;
    const unsigned char *s = source;
    while (count--) *d++ = *s++;
    return destination;
}

size_t my_strspn(const char *s, const char *accepted) {
    if (!*s || !*accepted) return 0;
    
    unsigned char is_accepted[256] = {0};
    const unsigned char *a = (const unsigned char *)accepted;
    while (*a) is_accepted[*a++] = 1;

    const unsigned char *p = (const unsigned char *)s;
    while (is_accepted[*p]) ++p;
    return p - (const unsigned char *)s;
}

size_t my_strcspn(const char *s, const char *rejected) {
    if (!*s) return 0;
    
    unsigned char is_rejected[256] = {1}; // sets only slot 0 ('\0') to rejected
    const unsigned char *r = (const unsigned char *)rejected;
    while (*r) is_rejected[*r++] = 1;

    const unsigned char *p = (const unsigned char *)s;
    while (!is_rejected[*p]) ++p;
    return p - (const unsigned char *)s;
}

char *my_strdup(const char *s) {
    char *dest = malloc(my_strlen(s) + 1);
    if (!dest) return NULL;
    return my_strcpy(dest, s);
}

char *string_slice(const char *s, size_t start, size_t length) {
    size_t string_length = my_strlen(s);
    if (start > string_length || length > string_length - start) return NULL;

    char *memory = malloc(length + 1);
    if (!memory) return NULL;

    memory[length] = '\0';
    return my_strncpy(memory, s + start, length);
}
