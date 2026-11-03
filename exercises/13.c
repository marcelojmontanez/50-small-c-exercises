#include "exercises.h"
#include "lib.h"

/* Compare the 2 strings lexicographically */
int my_strcmp(const char *a, const char *b) {
    while(*a == *b && *a != '\0') { ++a, ++b; }
    return (unsigned char)*a - (unsigned char)*b;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
