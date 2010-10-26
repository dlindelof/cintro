CC=gcc
CFLAGS=-ansi -pedantic -Wall

calc: main.o getop.o getch.o stack.o
	gcc -o calc main.o getop.o getch.o stack.o

clean:
	rm -f calc *.o *~