CC=gcc
CFLAGS=-ansi -pedantic -Wall -g

test: testlibchem
	./testlibchem

testlibchem: libchem.o testlibchem.o
	$(CC) -o testlibchem testlibchem.o libchem.o -lm

clean:
	rm -f testlibchem *.o *~
