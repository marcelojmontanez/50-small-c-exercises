#include "exercises.h"
#include "lib.h"

/* Tokenize a mutable string using caller-owned continuation state. */
char *next_token(char *s, const char *delimiters, char **state) {
    if (!s) s = *state;
    if (!s) return NULL;

    s += my_strspn(s, delimiters);
    if (!*s) return (*state = NULL);
    *state = s + my_strcspn(s, delimiters);
    if (**state) *(*state)++ = '\0';
    return s;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
