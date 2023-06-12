#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../expression-notation.h"

void test_infix_to_postfix(char input[], char expected_output[]) {
    char* output = malloc(strlen(input) + 1);
    strcpy(output, input);

    infix_to_postfix(output);

    if (strcmp(output, expected_output) == 0)
        printf("Test passed\n");
    else
        printf("Expected `%s`, got `%s`\n", expected_output, output);

    free(output);
}

int main(void) {
    test_infix_to_postfix("(A+B*C)", "ABC*+");
    test_infix_to_postfix("(A*(B+C)/D-E)", "ABC+*D/E-");
    test_infix_to_postfix("(A+B*(C-D*(E-F)-G*H)-I*3)", "ABCDEF-*-GH*-*+I3*-");
    test_infix_to_postfix("(A+B*C/D*E-F)", "ABC*D/E*+F-");
    test_infix_to_postfix("(A+B+C*D-E*F*G)", "AB+CD*+EF*G*-");
    test_infix_to_postfix("(A+(B-(C+(D-(E+F)))))", "ABCDEF+-+-+");
    test_infix_to_postfix("(A*(B+(C*(D+(E*(F+G))))))", "ABCDEFG+*+*+*");
}
