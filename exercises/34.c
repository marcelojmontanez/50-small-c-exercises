#include "exercises.h"
#include "lib.h"
#include <limits.h>

/* Parse a whole unsigned number in a caller-selected base. */
ParseResult parse_uint_base(const char *s, unsigned base, unsigned *result) {
    if (!*s) return PARSE_INVALID;

    if (base < 2 || base > 36) return PARSE_INVALID;

    unsigned value = 0;
    ParseResult status = PARSE_OK;
    while (*s) {
        if (!my_isalnum(*s)) return PARSE_INVALID;

        unsigned char c = my_tolower(*s);
        unsigned digit = (c - (my_isdigit(c) ? '0' : 'a' - 10));
        if (digit >= base) return PARSE_INVALID;

        if (status == PARSE_OK) {
            if (value > (UINT_MAX - digit) / base)
                status = PARSE_OVERFLOW;
            else
                value = base * value + digit;
        }
        ++s;
    }
    if (status == PARSE_OK) *result = value;
    return status;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
