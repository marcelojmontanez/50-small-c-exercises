#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Append arbitrary bytes to a growable owned buffer. */
int buffer_append(ByteBuffer *buffer, const void *data, size_t count) {
    if (count > SIZE_MAX - buffer->length) return -1;
    size_t grown_length = buffer->length + count;
    if (grown_length > buffer->capacity) {
        size_t grown_capacity = grown_length;
        if (buffer->capacity <= SIZE_MAX / 2 && buffer->capacity * 2 > grown_length) {
            grown_capacity = buffer->capacity * 2;
        }
        
        unsigned char *grown_data = realloc(buffer->data, grown_capacity);
        if (!grown_data) return -1;
        buffer->data = grown_data;
        buffer->capacity = grown_capacity;
    }

    my_memcpy(buffer->data + buffer->length, data, count);
    buffer->length = grown_length;

    return 0;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
