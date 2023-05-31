#include <stdbool.h>

#define STACK_SIZE 64

typedef struct {
    char elements[STACK_SIZE];
    int top_index;
} Stack;

Stack stack_new(void);
bool stack_is_full(Stack stack);
bool stack_is_empty(Stack stack);
void stack_push(Stack* stack, char value);
char stack_pop(Stack* stack);
char stack_peek(Stack stack);
void stack_display(Stack stack);
