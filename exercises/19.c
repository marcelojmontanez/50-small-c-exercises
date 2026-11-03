#include "exercises.h"
#include "lib.h"

/* Append at most count source bytes, then a terminator. */
char *my_strncat(char *destination, const char *source, size_t count) {
    char *d = destination + my_strlen(destination);
    while (*d) ++d;
    while (count-- && *source) *d++ = *source++;
    *d = '\0';
    return destination;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
