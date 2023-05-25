#include "infix.h"
#include "string.h"

#define POSTFIX_EXPR_SIZE 256

typedef struct {
	char expr[POSTFIX_EXPR_SIZE];
} Postfix;

Postfix postfix_new(char expr[POSTFIX_EXPR_SIZE]) {
	char sized_expr[POSTFIX_EXPR_SIZE];
    strcpy(sized_expr, expr);

	Postfix postfix;
	strcpy(postfix.expr, sized_expr);
    
	return postfix;
}

Postfix postfix_from(Infix infix);
