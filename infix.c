#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INFIX_EXPR_SIZE 256

typedef struct {
	char expr[INFIX_EXPR_SIZE];
} Infix;

void assert_msg(bool condition, char msg[]) {
    if (!condition) {
        printf("%s", msg);
        exit(EXIT_FAILURE);
    }
}

void insert_char(char* str, char ch, int index) {
    assert_msg(strlen(str) + 1 < INFIX_EXPR_SIZE, "String length exceeded size limit!\n");
    assert_msg(index <= strlen(str), "Index exceeded string length!\n");

    // Shift everything to the right from and including index.
    for (int i = strlen(str); i >= index; i--) {
        str[i + 1] = str[i];
    }

    str[index] = ch;
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool is_operand(char ch) {
    return ch != ' ' && !is_operator(ch);
}

int get_operator_priority(char operator) {
    return operator == '+' || operator == '-' ? 0 : 1;
}

int get_closing_parenthesis_index(Infix infix, int opening_parenthesis_i) {
    const char opening_parenthesis = infix.expr[opening_parenthesis_i];
    assert_msg(opening_parenthesis == '(' || opening_parenthesis == ')', "Opening parenthesis index does not lead to a parenthesis!\n");

    const bool traverse_right = opening_parenthesis == '(';
    const char closing_parenthesis = traverse_right ? ')' : '(';
    int parenthesis_depth = 1;

    for (
        int i = opening_parenthesis_i + (traverse_right ? 1 : -1);
        traverse_right ? i < strlen(infix.expr) : i >= 0;
        traverse_right ? i++ : i--
    ) {
        const char ch = infix.expr[i];

        if (ch == opening_parenthesis) {
            parenthesis_depth++;
        } else if (ch == closing_parenthesis) {
            parenthesis_depth--;

            if (parenthesis_depth == 0) {
                return i;
            }
        }
    }

    printf("Could not find a closing parenthesis for the opening parenthesis at index %i!\n", opening_parenthesis_i);
    exit(EXIT_FAILURE);
}

int get_right_operand_index(Infix infix, int operator_index) {
    assert_msg(is_operator(infix.expr[operator_index]), "Operator index does not lead to an operator!\n");

    for (int i = operator_index + 1; i < strlen(infix.expr); i++) {
        char ch = infix.expr[i];

        if (is_operand(ch)) {
            return i;
        }
    }

    printf("Could not find an operand on the right of the operator of index %i!\n", operator_index);
    exit(EXIT_FAILURE);
}

int get_left_operand_index(Infix infix, int operator_index) {
    assert_msg(is_operator(infix.expr[operator_index]), "Operator index does not lead to an operator!\n");

    for (int i = operator_index - 1; i >= 0; i--) {
        char ch = infix.expr[i];

        if (is_operand(ch)) {
            return i;
        }
    }

    printf("Could not find an operand on the left of the operator of index %i!\n", operator_index);
    exit(EXIT_FAILURE);
}

bool is_operator_parenthesized(Infix infix, int operator_index) {
    const int right_operand_i = get_right_operand_index(infix, operator_index);
    const int right_parenthesis_i = infix.expr[right_operand_i] == '('
        ? get_closing_parenthesis_index(infix, right_operand_i) + 1
        : right_operand_i + 1;
    const bool right_flag = infix.expr[right_parenthesis_i] == ')';

    const int left_operand_i = get_left_operand_index(infix, operator_index);
    const int left_parenthesis_i = infix.expr[left_operand_i] == ')'
        ? get_closing_parenthesis_index(infix, left_operand_i) - 1
        : left_operand_i - 1;
    const bool left_flag = infix.expr[left_parenthesis_i] == '(';

    return right_flag && left_flag;
}

Infix parenthesize_operator(Infix infix, int operator_index) {
    assert_msg(!is_operator_parenthesized(infix, operator_index), "Operator is already parenthesized!\n");

    const int right_operand_i = get_right_operand_index(infix, operator_index);
    const int right_parenthesis_i = infix.expr[right_operand_i] == '('
        ? get_closing_parenthesis_index(infix, right_operand_i)
        : right_operand_i + 1;

    insert_char(infix.expr, ')', right_parenthesis_i);

    const int left_operand_i = get_left_operand_index(infix, operator_index);
    const int left_parenthesis_i = infix.expr[left_operand_i] == ')'
        ? get_closing_parenthesis_index(infix, left_operand_i)
        : left_operand_i;

    insert_char(infix.expr, '(', left_parenthesis_i);

    return infix;
}

// Returns an Infix with an increased capacity expression for possible future operations on it.
Infix infix_new(char expr[INFIX_EXPR_SIZE]) {
    char sized_expr[INFIX_EXPR_SIZE];
    strcpy(sized_expr, expr);

	Infix infix;
	strcpy(infix.expr, sized_expr);
    
	return infix;
}

// Returns an Infix with its expression fully parenthesized, taking into account operator precedence.
Infix infix_parenthesize(Infix infix) {
    for (int i = 0; i < strlen(infix.expr); i++) {
        const char ch = infix.expr[i];

        if (!is_operator(ch) || ch == '+' || ch == '-' || is_operator_parenthesized(infix, i))
            continue;

        return infix_parenthesize(parenthesize_operator(infix, i));
    }

    for (int i = 0; i < strlen(infix.expr); i++) {
        const char ch = infix.expr[i];

        if (!is_operator(ch) || is_operator_parenthesized(infix, i))
            continue;

        return infix_parenthesize(parenthesize_operator(infix, i));
    }

    return infix;
}
