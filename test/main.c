#include <stdio.h>
#include "../postfix.h"

int main(void) {
	Infix infix = infix_new("1 + 1");
	Postfix postfix = postfix_from(infix);

	puts(postfix.expr);
}
