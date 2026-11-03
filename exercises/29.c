#include "exercises.h"
#include "lib.h"

/* Find the first string character belonging to accepted. */
char *my_strpbrk(const char *s, const char *accepted) {
    s += my_strcspn(s, accepted);
    return *s ? (char *)s : NULL;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
