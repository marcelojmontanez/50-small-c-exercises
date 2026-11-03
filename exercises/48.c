#include "exercises.h"
#include "lib.h"
#include <stdlib.h>

/* Allocate and append one node to a singly linked list. */
int list_push_back(IntNode **head, int value) {
    IntNode *node = malloc(sizeof *node);
    if (!node) return -1;
    node->value = value;
    node->next = NULL;

    IntNode **slot = head;
    while (*slot) slot = &(*slot)->next;
    *slot = node;

    return 0;
}

/* Free all nodes without accessing them after release. */
void list_free(IntNode *head) {
    while (head) {
        IntNode *next = head->next;
        free(head);
        head = next;
    }
}

#ifndef EXERCISE_TEST
int main(void) { return 0; }
#endif
