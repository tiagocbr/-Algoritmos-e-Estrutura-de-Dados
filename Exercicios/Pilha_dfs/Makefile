all: pilha.o main.o 
	gcc  pilha.o main.o  -o main -std=c99 -Wall


Pilha.o: pilha.c pilha.h
	gcc -c pilha.c -o pilha.o
	 
main.o: main.c pilha.h
	gcc -c main.c -o main.o
 
clean:
	rm *.o main

run:
	./main
