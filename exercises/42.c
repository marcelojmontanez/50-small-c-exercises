#include "exercises.h"
#include "lib.h"

/* Decode four little-endian bytes without alignment assumptions. */
uint32_t read_u32_le(const unsigned char bytes[4]) {
    return (uint32_t)bytes[0] 
         | (uint32_t)bytes[1] << 8 
         | (uint32_t)bytes[2] << 16 
         | (uint32_t)bytes[3] << 24;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
