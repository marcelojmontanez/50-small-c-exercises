#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Allocate strings joined by a separator. */
char *string_join(const char *const *strings, size_t count, const char *separator) {
    if (!count) return my_strdup("");

    size_t sep_length = my_strlen(separator);
    size_t join_length = my_strlen(strings[0]);
    for (size_t i = 1; i < count; ++i) {
        if (sep_length > SIZE_MAX - join_length) return NULL;
        join_length += sep_length;

        size_t length = my_strlen(strings[i]);
        if (length > SIZE_MAX - join_length) return NULL;
        join_length += length;
    }
    if (join_length == SIZE_MAX) return NULL;
    char *joined = malloc(join_length + 1);
    if (!joined) return NULL;

    char *cursor = joined;
    const char *string = strings[0];
    while ((*cursor = *string)) {
        ++cursor; ++string;
    }
    for (size_t i = 1; i < count; ++i) {
        my_memcpy(cursor, separator, sep_length);
        cursor += sep_length;
        string = strings[i];
        while ((*cursor = *string)) {
            ++cursor; ++string;
        }
    }

    return joined;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
