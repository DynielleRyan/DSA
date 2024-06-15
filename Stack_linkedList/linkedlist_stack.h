#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} stackLinkedList;

void initStack(stackLinkedList* s);
stackLinkedList createStack();

bool stack_push(stackLinkedList* s, int elem);
bool stack_pop(stackLinkedList* s);
int stack_peek(stackLinkedList s);

void display(stackLinkedList s);
void visualize(stackLinkedList s);
