#include "exercises.h"
#include "lib.h"

/* Return the absolute value; the contract excludes INT_MIN. */
int my_abs(int value) {
    if (value < 0) return -value;
    return value;
}

#ifndef EXERCISE_TEST
int main(void) {
    printf("my_abs(-42) = %d\n", my_abs(-42));
    return 0;
}
#endif
