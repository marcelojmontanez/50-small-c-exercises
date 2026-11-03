#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Read one owned line of arbitrary length; distinguish EOF from errors. */
int read_line(FILE *stream, char **line, size_t *length) {
    *line = NULL;
    *length = 0;
    ByteBuffer buffer = {0};

    int c;
    while ((c = fgetc(stream)) != EOF && c != '\n') {
        unsigned char byte = (unsigned char)c;
        if (buffer_append(&buffer, &byte, 1) < 0) {
            free(buffer.data);
            return -1;
        }
    }

    if (ferror(stream)) {
        free(buffer.data);
        return -1;
    }

    if (c == EOF && buffer.length == 0) return 0;

    if (buffer_append(&buffer, "", 1) < 0) {
        free(buffer.data);
        return -1;
    }
    *line = (char *)buffer.data;
    *length = buffer.length - 1;

    return 1;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
