#include "exercises.h"
#include "lib.h"

/* Uppercase an ASCII lowercase letter; preserve every other int. */
int my_toupper(int c) {
    if ('a' <= c && c <= 'z') return c + 'A' - 'a';
    return c;
}

#ifndef EXERCISE_TEST
int main(void) {
    printf("my_toupper('g') = %d\n", my_toupper('g'));
    return 0;
}
#endif
