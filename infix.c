#include <string.h>

#define INFIX_EXPR_MAX_SIZE 256

typedef struct {
	char expr[INFIX_EXPR_MAX_SIZE];
} Infix;

Infix infix_new(char expr[INFIX_EXPR_MAX_SIZE]) {
	Infix infix;
	strcpy_s(infix.expr, INFIX_EXPR_MAX_SIZE, expr);

	return infix;
}
