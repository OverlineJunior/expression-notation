#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 64
#define INT_NONE -1

void assert_msg(bool condition, char msg[]) {
    if (!condition) {
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

typedef struct {
    char elements[STACK_SIZE];
    int top_index;
} Stack;

// Returns a new empty stack.
Stack stack_new(void) {
    Stack stack = { .top_index = INT_NONE };
    return stack;
}

bool stack_is_full(Stack stack) {
    return stack.top_index == STACK_SIZE - 1;
}

bool stack_is_empty(Stack stack) {
    return stack.top_index == INT_NONE;
}

/// @brief Appends `value` to the top of the stack.
/// @exception Cannot push to full stack.
void stack_push(Stack* stack, char value) {
    assert_msg(!stack_is_full(*stack), "Cannot push to full stack!");

    stack->elements[++stack->top_index] = value;
}

/// @brief Removes the top element from the stack.
/// @return Value popped.
/// @exception Cannot pop from empty stack.
char stack_pop(Stack* stack) {
    assert_msg(!stack_is_empty(*stack), "Cannot pop from empty stack!");

    return stack->elements[stack->top_index--];
}

// Returns the top element from the stack without popping it out.
char stack_peek(Stack stack) {
    assert_msg(!stack_is_empty(stack), "Cannot peek empty stack!");

    return stack.elements[stack.top_index];
}

void stack_display(Stack stack) {
    printf("[");

    for (int i = 0; i <= stack.top_index; i++)
        if (i == stack.top_index)
            printf("%c", stack.elements[i]);
        else
            printf("%c, ", stack.elements[i]);

    printf("]\n");
}
