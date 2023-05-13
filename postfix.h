#include "infix.h"

#define POSTFIX_EXPR_MAX_SIZE 256

typedef struct {
	char expr[POSTFIX_EXPR_MAX_SIZE];
} Postfix;

Postfix postfix_from(Infix infix);
