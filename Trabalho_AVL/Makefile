all: main.o item.o avl.o set.o
	gcc -o main main.o item.o avl.o set.o
main.o: main.c item.h avl.h set.h
	gcc -c main.c
item.o: item.c item.h
	gcc -c item.c
avl.o: avl.c item.h avl.h
	gcc -c avl.c
set.o: set.c item.h avl.h set.h
	gcc -c set.c
clean: 
	rm *.o main
run:
	./main