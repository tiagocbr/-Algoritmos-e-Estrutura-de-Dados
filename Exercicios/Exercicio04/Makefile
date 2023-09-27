all: item.o lista.o main.o
	gcc -o main item.o lista.o main.o
item.o: item.c item.h
	gcc -c item.c
lista.o: lista.c item.h lista.h
	gcc -c lista.c
main.o: main.c item.h lista.h
	gcc -c main.c
clean:
	rm *.o main
run:
	./main