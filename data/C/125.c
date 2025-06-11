#include <stdio.h>
#include <stdlib.h>

// Snippet 5: Stack Implementation (Push and Pop)
struct Stack {
    int *arr;
    int top;
    int capacity;
};

void push(struct Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) return;
    stack->arr[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (stack->top == -1) return -1;
    return stack->arr[stack->top--];
}

void stack_operations() {
    struct Stack stack;
    stack.capacity = 100;
    stack.top = -1;
    stack.arr = (int*) malloc(stack.capacity * sizeof(int));

    push(&stack, 10);
    push(&stack, 20);
    int popped = pop(&stack);

    free(stack.arr);
}

int main() {
    stack_operations();
    return 0;
}