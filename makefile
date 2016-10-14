GCC = gcc -g

all: tunez.o
	$(GCC) list.o main.o -o tunetest

tunez.o: tunez.c tunez.h
	$(GCC) -c tunez.c

clean:
	rm *.o
	rm *~

run: all
	./tunetest.out
