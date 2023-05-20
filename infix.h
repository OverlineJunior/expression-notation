#define INFIX_EXPR_MAX_SIZE 256

typedef struct {
	char expr[INFIX_EXPR_MAX_SIZE];
} Infix;

Infix infix_new(char expr[INFIX_EXPR_MAX_SIZE]);
Infix parenthesize_operator(Infix infix, int op_index); // TODO: Remove after testing.
Infix infix_parenthesize(Infix infix);
