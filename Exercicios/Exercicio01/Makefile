all: circulo.o ponto.o main.o
	gcc circulo.o ponto.o main.c -o main -std=c99 -Wall -lm

ponto.o: ponto.c ponto.h
	gcc -c ponto.c -o ponto.o
	
circulo.o: circulo.c circulo.h ponto.h
	gcc -c circulo.c -o circulo.o

run:
	./main
clean:
	rm *.o
	rm main
