#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 5
typedef struct{
	int data[MAX];
	int top;
}stackArrayList;

void initStack(stackArrayList *s);
StackArrayList createStack();

bool stack_push(stackArrayList *s, int elem);
bool stack_pop(stackArrayList *s);
int stack_peek(StackArrayList s);

void display(stackARrayList s);
void visualize(stackArrayList s);
