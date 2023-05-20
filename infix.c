#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INFIX_EXPR_SIZE 256

typedef struct {
	char expr[INFIX_EXPR_SIZE];
} Infix;

void assert_msg(bool condition, char msg[]) {
    if (!condition) {
        printf("%s", msg);
        exit(EXIT_FAILURE);
    }
}

void insert_char(char* str, char ch, int index) {
    assert_msg(strlen(str) + 1 < INFIX_EXPR_SIZE, "String length exceeded size limit!\n");
    assert_msg(index <= strlen(str), "Index exceeded string length!\n");

    // Shift everything to the right from and including index.
    for (int i = strlen(str); i >= index; i--) {
        str[i + 1] = str[i];
    }

    str[index] = ch;
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

Infix infix_new(char expr[INFIX_EXPR_SIZE]) {
    char sized_expr[INFIX_EXPR_SIZE];
    strcpy_s(sized_expr, INFIX_EXPR_SIZE, expr);

	Infix infix;
	strcpy_s(infix.expr, INFIX_EXPR_SIZE, sized_expr);

	return infix;
}

Infix infix_parenthesize_operator(Infix infix, int op_index) {
    // Traverse right.
    for (int i = op_index + 1; i < strlen(infix.expr); i++) {
        char ch = infix.expr[i];

        if (ch == ' ' || is_operator(ch)) continue;

        insert_char(infix.expr, ')', i + 1);
        break;
    }

    // Traverse left.
    for (int i = op_index - 1; i >= 0; i--) {
        char ch = infix.expr[i];

        // Also ignore operators.
        if (ch == ' ') continue;

        insert_char(infix.expr, '(', i);
        break;
    }

    return infix;
}

Infix infix_parenthesize(Infix infix);
