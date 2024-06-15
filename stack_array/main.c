#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
 stackArrayList stack = createStack();

    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);

    display(&stack);
    visualize(&stack);

    int popped;
    if (stack_pop(&stack, &popped)) {
        printf("Popped: %d\n", popped);
    }

    display(&stack);
    visualize(&stack);

	return 0;
}
