#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Allocate an independent copy of count integers. */
int *array_clone(const int *values, size_t count) {
    if (!count || count > SIZE_MAX / sizeof(int)) return NULL;
    
    int *memory = malloc(count * sizeof(int));
    if (!memory) return NULL;
    return my_memcpy(memory, values, count * sizeof(int));
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
