#include "exercises.h"
#include "lib.h"

/* Parse an atoi-style decimal prefix within the documented int range. */
int my_atoi(const char *s) {
    while (my_isspace(*s)) ++s;
    
    int sign = 1;
    if (*s == '+') ++s;
    else if (*s == '-') { sign = -1; ++s; }

    int value = 0;
    while (my_isdigit(*s)) {
        value = 10 * value + sign * (*s - '0');
        ++s;
    }

    return value;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
