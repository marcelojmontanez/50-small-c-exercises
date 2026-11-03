#include "exercises.h"
#include "lib.h"

/* Find the first matching unsigned byte within count bytes. */
void *my_memchr(const void *memory, int value, size_t count) {
    const unsigned char *m = memory;
    while (count && *m != (unsigned char)value) { ++m; --count; }
    return count ? (void *)m : NULL;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
