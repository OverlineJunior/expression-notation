all: main.exe run

main.exe: main.c ../expression-notation.c ../libs/stack.c
	@clang -Wall -Wno-deprecated-declarations -o main.exe main.c ../expression-notation.c ../libs/stack.c

run:
	@./main.exe
