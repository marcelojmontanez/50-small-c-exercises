#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Append an integer, growing owned storage when necessary. */
int vector_push(IntVector *vector, int value) {
    if (vector->length != vector->capacity) {
        vector->data[vector->length] = value;
        ++vector->length;
        return 0;
    }

    if (vector->capacity > SIZE_MAX / 2) return -1;
    size_t grown_capacity = vector->capacity ? vector->capacity * 2 : 1;
    
    if (grown_capacity > SIZE_MAX / sizeof(int)) return -1;
    int *grown_data = realloc(vector->data, grown_capacity * sizeof(int));
    if (!grown_data) return -1;

    vector->capacity = grown_capacity;
    vector->data = grown_data;
    vector->data[vector->length++] = value;
    
    return 0;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
