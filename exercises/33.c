#include "exercises.h"
#include "lib.h"

/* Format an int as decimal into a caller-owned buffer. */
int int_to_string(int value, char *destination, size_t capacity) {
    if (!capacity) return -1;

    size_t length = 0;
    int v = value;
    if (v < 0) ++length;
    do {
        ++length;
        v /= 10;
    } while (v);
    if (length + 1 > capacity) return -1;

    destination += length;
    *destination = '\0';
    v = value;
    do {
        *--destination = (v > 0 ? v % 10 : -(v % 10)) + '0';
        v /= 10;
    } while (v);
    if (value < 0) *--destination = '-';

    return 0;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
