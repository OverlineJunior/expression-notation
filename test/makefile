all: main.exe run

main.exe: main.c ../expression-notation.c ../libs/stack.c ../libs/my_assert.c
	@clang -Wall -Wno-deprecated-declarations -o main.exe main.c ../expression-notation.c ../libs/stack.c ../libs/my_assert.c

run:
	@./main.exe
