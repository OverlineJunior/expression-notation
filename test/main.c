#include <stdio.h>
#include "../postfix.h"

int main(void) {
	Infix infix = infix_new("(2 + 1) - ((6 / 3) + 2)");
	infix = infix_parenthesize_operator(infix, 8);
	printf("%s", infix.expr);
}
