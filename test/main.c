#include <stdio.h>
#include "../postfix.h"

int main(void) {
	Infix infix = infix_new("1 + 2 * 3 - (2 + 1)");
	infix = infix_parenthesize(infix);

	printf("%s", infix.expr);
}
