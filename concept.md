```c
char* postfix_from(Infix infix);

// Expression -> infix_parenthesize() -> postfix_from()
// "1 + 1 * 2" -> "(1 + (1 * 2))" -> "1 2 * 1 +"
postfix_from(infix_new("1 + 1")) // "1 1 +"

/*
(((3 + 6) * (2 - 4)) + 7)
(( * (2 - 4)) + 7)   3 6 +
(( * ) + 7)   3 6 + 2 4 -
( + 7)   3 6 + 2 4 - *
3 6 + 2 4 - * 7 +
*/
```
