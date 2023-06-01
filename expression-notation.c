#include <string.h>
#include "libs/stack.h"

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool is_operand(char ch) {
    return !is_operator(ch) && ch != ' ' && ch != '(' && ch != ')';
}

void infix_to_postfix(char* expr) {
    Stack operators = stack_new();
    char buffer[strlen(expr)]; // TODO: Don't forget to add \0 at the end.

    for (int i = 0; i < strlen(expr); i++) {
        const char token = expr[i];

        if (is_operand(token))
            strcat(buffer, &token);

        
    }

    strcpy(expr, buffer);
}
