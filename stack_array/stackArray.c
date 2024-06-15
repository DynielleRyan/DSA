#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"StackArray.h"


#ifndef STACK_ARRAY
#define STACK_ARRAY

/*typedef struct{
	int data[MAX];
	int top;
}stackArrayList;

void initStack(stackArrayList *s);
stackArrayList createStack();

bool stack_push(stackArrayList *s, int elem);
bool stack_pop(stackArrayList *s);
int stack_peek(StackArrayList s);

void display(stackARrayList s);
void visualize(stackArrayList s);

*/ 


void initStack(stackArrayList *s){
	
	s->top = -1;

}


stackArrayList createStack(){
	
	stackArrayList newStack
	initStack(&newStack);
	
	return newStack;
	
}


bool stack_push(stackArrayList *s, int elem){
	if (s->top == MAX){
		printf("Array is already full")
		return false;
	}
	s->top++
	s->data[s->top] = elem;
	
	//if an element is added to the stack, then return true;
	return true;
}

bool stack_pop(stackArrayList *s){
	if(s->top == - 1){ //mucheck ni siya if empty ba ang stack or dili
		return false;
	}
	
	*elem = s->data[s->top];
	return true;
}

int stack_peek(stackArrayList *s){
	if(s->top == -1){
		
		return -1;
	}
	
	return s->data[s->top];
}

void display(stackArrayList *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

void visualize(stackArrayList *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            if (i == s->top) {
                printf("[%d] : %d (top)\n", i, s->data[i]);
            } else {
                printf("[%d] : %d\n", i, s->data[i]);
            }
        }
    }
}










