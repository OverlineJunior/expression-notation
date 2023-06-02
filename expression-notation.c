#include <string.h>
#include <stdlib.h>
#include "libs/stack.h"
#include "libs/my_assert.h"

#define NONE -1

void push_char(char* dest, char ch) {
    int len = strlen(dest);

    dest[len] = ch;
    dest[len + 1] = '\0';
}

bool is_operator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

bool is_operand(char token) {
    return !is_operator(token) && token != ' ' && token != '(' && token != ')';
}

bool is_parenthesis(char token) {
    return token == '(' || token == ')';
}

int input_precedence(char token) {
    assert_msg(is_operator(token) || is_parenthesis(token), "Only operators and parenthesis have precedence!");

    if (token == ')') {
        return 0;
    } else if (token == '(') {
        return 5;
    } else if (token == '+' || token == '-') {
        return 1;
    } else if (token == '*' || token == '/') {
        return 3;
    }

    return NONE;
}

int stack_precedence(char token) {;
    assert_msg(is_operator(token) || is_parenthesis(token), "Only operators and parenthesis have precedence!");

    if (token == ')') {
        return NONE;
    } else if (token == '(') {
        return 0;
    } else if (token == '+' || token == '-') {
        return 2;
    } else if (token == '*' || token == '/') {
        return 4;
    }

    return NONE;
}

void infix_to_postfix(char* expr) {
    Stack stack = stack_new();
    stack_push(&stack, '(');

    push_char(expr, ')');

    char* buffer = malloc(strlen(expr) + 1); // + 1 for the null terminator.
    strcpy(buffer, ""); // Removes a garbage value at index 0.

    for (int i = 0; i < strlen(expr); i++) {
        const char token = expr[i];

        if (is_operand(token)) {
            push_char(buffer, token);
        } else {
            while (
                !stack_is_empty(stack) &&
                stack_precedence(stack_peek(stack)) >= input_precedence(token)
            ) {
                const char top = stack_pop(&stack);

                if (top == '(')
                    break;

                push_char(buffer, top);
            }

            if (token != ')')
                stack_push(&stack, token);
        }
    }

    strcpy(expr, buffer);
    free(buffer);
}
