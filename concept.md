```c
char* postfix_from(Infix infix);

// Expression -> infix_parenthesize() -> postfix_from()
// "1 + 1 * 2" -> "(1 + (1 * 2))" -> "1 2 * 1 +"
postfix_from(infix_new("1 + 1")) // "1 1 +"
```
