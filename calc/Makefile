CC=gcc
CFLAGS=-ansi -pedantic -Wall

calc: main.o getop.o getch.o stack.o
	gcc -o calc main.o getop.o getch.o stack.o -lm

clean:
	rm -f calc *.o *~
