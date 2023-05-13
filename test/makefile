all: main.exe run

main.exe: main.c ../postfix.c ../infix.c
	@clang -Wall -o main.exe main.c ../postfix.c ../infix.c

run:
	@./main.exe
