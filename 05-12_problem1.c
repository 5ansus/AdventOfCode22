#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 52
#define MAX_STACKS 9

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void stack_Init(Stack *stack) {
    stack->top = -1;
}

void stack_Print(Stack *stack) {
    int i;
    if(stack->top == -1) {
        printf("Empty Stack Uwu\n");
    }
    
    for(i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
}

void stack_Insert(Stack *stack, int elem) {
    (stack->top)++;
    stack->arr[stack->top] = elem;
    
}

int main() {
    FILE *pf = NULL;
    Stack arrStacks[MAX_STACKS];
    int numMoves, from, to;
    int i;

    for(i = 0; i < MAX_STACKS; i++) {
        stack_Init(&arrStacks[i]);
        stack_Print(&arrStacks[i]);
    }

    pf = fopen("05-12_input.txt", "r");
    if(pf == NULL) return 1;

    while(fscanf(pf, "move %d from %d to %d\n", &numMoves, &from, &to) != EOF) {

    }



    fclose(pf);
    return 0;
}
