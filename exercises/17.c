#include "exercises.h"
#include "lib.h"

/* Compare at most count bytes of the two strings. */
int my_strncmp(const char *a, const char *b, size_t count) {
    if (!count) return 0;
    while (--count && *a == *b && *a != '\0') { ++a; ++b; }
    return (unsigned char)*a - (unsigned char)*b;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
