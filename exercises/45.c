#include "exercises.h"
#include "lib.h"

/* Binary-search sorted fixed-size records using a comparator callback. */
void *my_bsearch(const void *key, const void *base, size_t count, size_t size,
                 int (*compare)(const void *, const void *)) {
    const unsigned char *start = base;
    while (count > 0) {
        const unsigned char *middle = start + (count / 2) * size;
        int comparison = compare(key, middle);
        if (comparison < 0) {
            count /= 2;
        } else if (comparison > 0) {
            start = middle + size;
            count -= count / 2 + 1;
        } else { 
            return (void *)middle;
        }
    }
    return NULL;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
