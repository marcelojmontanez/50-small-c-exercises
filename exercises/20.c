#include "exercises.h"
#include "lib.h"

/* Reverse a writable string's bytes in place, preserving its terminator. */
void reverse_string(char *s) {
    if (!*s) return;

    char *right = s + my_strlen(s) - 1;
    for (char *left = s; left < right; ++left, --right) {
        char temp = *left;
        *left = *right;
        *right = temp;
    }
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
