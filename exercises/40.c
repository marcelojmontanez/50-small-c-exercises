#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Split into separately allocated fields; preserve empty fields. */
char **string_split(const char *s, char delimiter, size_t *count) {
    *count = 0;
    size_t field_count = 1;
    for (const char *p = s; *p; ++p) {
        if (*p == delimiter) ++field_count;
    }
    
    if (field_count > SIZE_MAX / sizeof(char *)) return NULL;
    char **fields = malloc(field_count * sizeof(char *));
    if (!fields) return NULL;

    const char *start = s;
    for (size_t i = 0; i < field_count; ++i) {
        const char *end = start;
        while (*end && *end != delimiter) ++end;

        size_t length = end - start;
        char *field = malloc(length + 1);
        if (!field) {
            string_split_free(fields, i);
            return NULL;
        }
        field[length] = '\0';

        fields[i] = my_memcpy(field, start, length);
        start = end + 1;
    }

    *count = field_count;
    return fields;
}

/* Release every field and the pointer array. */
void string_split_free(char **strings, size_t count) {
    for (size_t i = 0; i < count; ++i) free(strings[i]);
    free(strings);
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
