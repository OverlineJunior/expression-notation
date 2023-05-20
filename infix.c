#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INFIX_EXPR_MAX_SIZE 256

typedef struct {
	char expr[INFIX_EXPR_MAX_SIZE];
} Infix;

void assert_msg(bool condition, char msg[]) {
    if (!condition) {
        printf("%s", msg);
        exit(EXIT_FAILURE);
    }
}

void insert_char(char* str, char ch, int index) {
    assert_msg(strlen(str) + 1 < 100, "String length exceeded size limit!\n");
    assert_msg(index < strlen(str), "Index exceeded string length!\n");

    // Shift everything to the right from and including index.
    for (int i = strlen(str); i >= index; i--) {
        str[i + 1] = str[i];
    }

    str[index] = ch;
}

Infix infix_new(char expr[INFIX_EXPR_MAX_SIZE]) {
	Infix infix;
	strcpy_s(infix.expr, INFIX_EXPR_MAX_SIZE, expr);

	return infix;
}

Infix infix_parenthesize(Infix infix);
