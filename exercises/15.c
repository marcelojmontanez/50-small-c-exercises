#include "exercises.h"
#include "lib.h"

/* Return the last matching character's address, or NULL. */
char *my_strrchr(const char *s, int c) {
    const char *last = NULL;
    do {
        if (*s == (char)c) last = s;
    } while (*s++);
    return (char *)last;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
