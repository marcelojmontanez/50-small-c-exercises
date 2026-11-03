#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Unlink and free nodes selected by a callback; return removal count. */
size_t list_remove_if(IntNode **head, int (*predicate)(int)) {
    size_t removed_count = 0;
    IntNode **slot = head;
    while (*slot) {
        IntNode *node = *slot;
        if (predicate(node->value)) {
            *slot = node->next;
            free(node);
            ++removed_count;
        } else {
            slot = &node->next;
        }
    }

    return removed_count;
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
