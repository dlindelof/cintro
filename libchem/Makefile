CC=gcc
CFLAGS=-ansi -pedantic -Wall

test: testlibchem
	./testlibchem

testlibchem: libchem.o testlibchem.o
	$(CC) -o testlibchem testlibchem.o libchem.o -lm -lcunit

clean:
	rm -f testlibchem *.o *~
