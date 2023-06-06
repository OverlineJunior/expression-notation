#include <stdbool.h>

bool is_operator(char token);
bool is_operand(char token);
void infix_to_postfix(char* expr);
