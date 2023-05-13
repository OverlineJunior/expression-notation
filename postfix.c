#include "infix.h"
#include "string.h"

#define POSTFIX_EXPR_MAX_SIZE 256

typedef struct {
	char expr[POSTFIX_EXPR_MAX_SIZE];
} Postfix;

Postfix postfix_from(Infix infix) {
	Postfix postfix;
	strcpy_s(postfix.expr, POSTFIX_EXPR_MAX_SIZE, infix.expr);

	return postfix;
}
