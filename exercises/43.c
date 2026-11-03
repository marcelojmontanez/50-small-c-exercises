#include "exercises.h"
#include "lib.h"

/* Encode a 32-bit unsigned integer in four little-endian bytes. */
void write_u32_le(unsigned char bytes[4], uint32_t value) {
    bytes[0] = value & 0xFF;
    bytes[1] = value >> 8 & 0xFF;
    bytes[2] = value >> 16 & 0xFF;
    bytes[3] = value >> 24 & 0xFF;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
