#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/stack.h"

/// @brief Alternative to `strcat(dest, &ch)`, since it gives unexpected results.
/// @param dest Destination to push in. Modified by the function.
/// @param ch Character to push into `dest`.
void push_char(char* dest, char ch) {
    int len = strlen(dest);

    dest[len] = ch;
    dest[len + 1] = '\0';
}

/// @brief Returns the precedence of `token` coming from the input expression. Highly coupled to infix_to_postfix.
/// @return Integer such that the higher its value, the higher the token's precedence.
int input_precedence(char token) {
    switch (token) {
        case ')':
            return 0;
        case '(':
            return 5;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 1;
        default: {
            printf("Token `%c` does not have a precedence value as input!\n", token);
            exit(EXIT_FAILURE);
        }
    }
}

/// @brief Returns the precedence of `token` coming from the Shunting Yard algorithm's stack. Highly coupled to infix_to_postfix.
/// @return Integer such that the higher its value, the higher the token's precedence.
int stack_precedence(char token) {
    switch (token) {
        case '(':
            return 0;
        case '*':
        case '/':
            return 4;
        case '+':
        case '-':
            return 2;
        default: {
            printf("Token `%c` does not have a precedence value as a stack element!\n", token);
            exit(EXIT_FAILURE);
        }
    }
}

/// @return True if `token` is a supported operator, aka +, -, * or /.
bool is_operator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

/// @return True if `token` is a supported operand, aka anything other than an operator, whitespace or parenthesis.
bool is_operand(char token) {
    return !is_operator(token) && token != ' ' && token != '(' && token != ')';
}

/// @brief Converts the given expression to postfix using the Shunting Yard algorithm.
/// @param expr Infix expression to be converted. Modified by the function.
void infix_to_postfix(char* expr) {
    push_char(expr, ')'); // Allows expr to be sent without outer most parenthesis.

    Stack stack = stack_new();

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
