#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void assert_msg(bool condition, char msg[]) {
    if (!condition) {
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}
