#include "exercises.h"
#include "lib.h"
#include <limits.h>

/* Parse a whole decimal string, reporting syntax and range errors. */
ParseResult parse_int(const char *s, int *result) {
    int sign = 1;
    if (*s == '+') ++s;
    else if (*s == '-') { sign = -1; ++s; }

    if (!*s) return PARSE_INVALID;

    int value = 0;
    ParseResult status = PARSE_OK;
    while (*s) {
        if (!my_isdigit(*s)) return PARSE_INVALID;

        if (status == PARSE_OK) {
            int digit = sign * (*s - '0');
            if ((sign < 0 && value < (INT_MIN - digit) / 10) ||
                (sign > 0 && value > (INT_MAX - digit) / 10))
                status = PARSE_OVERFLOW;
            else value = 10 * value + digit;
        }
        ++s;
    }
    if (status == PARSE_OK) *result = value;
    return status;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
