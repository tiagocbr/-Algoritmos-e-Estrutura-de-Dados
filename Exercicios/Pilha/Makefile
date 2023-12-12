all: item.o Pilha.o main.o balanceada.o
	gcc item.o Pilha.o main.o balanceada.o -o balanceada -std=c99 -Wall

item.o: item.c Pilha.h item.h
	gcc -c item.c -o item.o

Pilha.o: pilha.c Pilha.h item.h
	gcc -c Pilha.c -o Pilha.o
	 
main.o: Pilha.h item.h
	gcc -c main.c -o main.o

balanceada.o: balanceada.c Pilha.h item.h
	gcc -c balanceada.c -o balanceada.o
	 
clean:
	rm *.o balanceada

run:
	./balanceada
