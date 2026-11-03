#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Allocate count * size zero bytes, checking multiplication first. */
void *my_calloc(size_t count, size_t size) {
    if (!count || !size) return NULL;
    if (count > SIZE_MAX / size) return NULL;

    size_t byte_count = count * size;
    void *memory = malloc(byte_count);
    if (!memory) return NULL;

    return my_memset(memory, 0, byte_count);
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
