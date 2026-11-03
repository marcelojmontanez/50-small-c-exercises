#include "exercises.h"
#include "lib.h"

/* Sort count integers in ascending order using insertion sort. */
void array_sort(int *values, size_t count) {
    for (size_t i = 1; i < count; ++i) {
        int current = values[i];
        size_t j;
        for (j = i; j > 0 && values[j - 1] > current; --j) {
            values[j] = values[j - 1];
            for (size_t k = 0; k < count; ++k) printf("%d ", values[k]);
            printf("\n");
        }
        values[j] = current;
    }
}   

#ifndef EXERCISE_TEST
int main(void) {
    int values[] = {5, 2, 9, 1, 7, 3};
    size_t count = sizeof values / sizeof values[0];

    array_sort(values, count);

    for (size_t i = 0; i < count; ++i) printf("%d ", values[i]);
    printf("\n");
    return 0;
}
#endif
