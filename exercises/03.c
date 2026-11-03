#include "exercises.h"
#include "lib.h"

/* Recognize ASCII letters or digits; reuse your earlier functions. */
int my_isalnum(int c) {
    return my_isdigit(c) || my_isalpha(c);
}

#ifndef EXERCISE_TEST
int main(void) {
    printf("my_isalnum('8') = %d\n", my_isalnum('8'));
    return 0;
}
#endif
