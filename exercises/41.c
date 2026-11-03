#include "exercises.h"
#include "lib.h"

/* Count one bits in an unsigned int. */
unsigned bit_count(unsigned value) {
    unsigned count = 0;
    while (value) {
        value &= value - 1;
        ++count;
    }
    return count;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
