all: main.exe run

main.exe: main.c ../expression-notation.c
	@clang -Wall -Wno-deprecated-declarations -o main.exe main.c ../expression-notation.c

run:
	@./main.exe
