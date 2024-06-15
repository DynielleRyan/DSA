#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedlist_stack.h"

stackLinkedList createStack() {
    stackLinkedList s;
    initStack(&s);
    return s;
}

bool stack_push(stackLinkedList* s, int elem) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = elem;
    new_node->next = s->top;
    s->top = new_node;
    return true;
}

bool stack_pop(stackLinkedList* s) {
    if (s->top == NULL) {
        return false;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return true;
}

int stack_peek(stackLinkedList s) {
    if (s.top == NULL) {
        return -1;
    }
    return s.top->data;
}

void display(stackLinkedList s) {
    Node* current = s.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void visualize(stackLinkedList s) {
    printf("Stack (top to bottom): ");
    display(s);
}

