all: main.exe run

main.exe: main.c ../postfix.c
	@clang -Wall -o main.exe main.c ../postfix.c

run:
	@./main.exe
