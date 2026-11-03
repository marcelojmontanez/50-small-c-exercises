#include "exercises.h"
#include "lib.h"

/* Copy count bytes correctly even when the regions overlap. */
void *my_memmove(void *destination, const void *source, size_t count) {
    unsigned char *d = destination;
    const unsigned char *s = source;

    if (d < s) {
        while (count--) *d++ = *s++;
        return destination;
    }
    
    d += count;
    s += count;
    while (count--) *--d = *--s;
    return destination;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
