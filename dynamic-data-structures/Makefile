all: main.exe

main.exe: main.o stack.o
	gcc -o main.exe main.o stack.o

main.o: main.c
	gcc -c main.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm stack.o main.o main.exe