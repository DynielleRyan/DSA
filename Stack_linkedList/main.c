#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "Linkedlist_stack.c"
#include "linkedlist_stack.h"

int main() {
    stackLinkedList stack = createStack();

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    printf("Stack after pushing 10, 20, 30:\n");
    visualize(stack);

    stack_pop(&stack);
    printf("Stack after popping one element:\n");
    visualize(stack);

    printf("Top element is: %d\n", stack_peek(stack));

    return 0;
}
