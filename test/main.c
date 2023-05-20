#include <stdio.h>
#include "../postfix.h"

int main(void) {
	Infix infix = infix_new("1 + 1");
	infix = parenthesize_operator(infix, 2);
	printf("%s\n", infix.expr);
}
