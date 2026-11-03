#include "exercises.h"
#include "lib.h"

/* Append source to destination; return destination. */
char *my_strcat(char *destination, const char *source) {
    char *d = destination + my_strlen(destination);
    while ((*d++ = *source++));
    return destination;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
