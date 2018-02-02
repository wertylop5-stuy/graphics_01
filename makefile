all: main.o
	gcc main.o

main.o:
	gcc -c main.c

clean:
	rm -f *.o a.out pic.ppm

