main: main.o conj.o
	gcc -o main main.o conj.o
main.o: main.c conj.h
	gcc -c main.c
conj.o: conj.c conj.h
	gcc -c conj.c
clean:
	rm *.o main