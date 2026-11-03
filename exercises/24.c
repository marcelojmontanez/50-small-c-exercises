#include "exercises.h"
#include "lib.h"

/* Compare count bytes as unsigned bytes, returning a sign. */
int my_memcmp(const void *a, const void *b, size_t count) {
    const unsigned char *l = a;
    const unsigned char *r = b;
    while (count && *l == *r) {
        --count; ++l; ++r;
    }
    return count ? *l - *r : 0;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
