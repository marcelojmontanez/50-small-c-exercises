#include "exercises.h"
#include "lib.h"

/* Return the first matching character's address, or NULL. */
char *my_strchr(const char *s, int c) {
    while (*s && *s != c) ++s;
    if (*s != c) return NULL;
    return s;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
