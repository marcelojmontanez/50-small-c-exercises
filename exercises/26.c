#include "exercises.h"
#include "lib.h"

/* Locate the first occurrence of needle in haystack. */
char *my_strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack;
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*n && *h == *n) {
            ++h; ++n;
        }
        if (!*n) return (char *)haystack;
        ++haystack;
    }
    return NULL;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
