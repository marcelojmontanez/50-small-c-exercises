#include "exercises.h"
#include "lib.h"

/* Sort count integers in ascending order using insertion sort. */
void array_sort(int *values, size_t count) {
    for (size_t i = 1; i < count; ++i) {
        int current = values[i];
        size_t j;
        for (j = i; j > 0 && values[j - 1] > current; --j) {
            values[j] = values[j - 1];
        }
        values[j] = current;
    }
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
