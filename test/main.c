#include <stdio.h>
#include "../expression-notation.h"

int main(void) {
    char expr[] = "(1 + 2) * 3";
    printf("%s\n", expr);
    infix_to_postfix(expr);
    printf("%s\n", expr);
}
