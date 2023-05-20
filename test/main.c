#include <stdio.h>
#include "../postfix.h"

int main(void) {
	Infix infix = infix_new("1 + 1 * 2 + 1");
	infix = infix_parenthesize_operator(infix, 6);
	printf("%s", infix.expr);
}
