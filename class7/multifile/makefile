CFLAGS = --std=c11 -Wall -pedantic
CC = gcc

all: multifile

multifile: multifile.o myfile.o
	$(CC) $(CFLAGS) multifile.o myfile.o -o multifile

multifile.o: multifile.c
	$(CC) $(CFLAGS) multifile.c -c
	
myfile.o: myfile.c
	$(CC) $(CFLAGS) myfile.c -c

clean:
	rm multifile *.o
	
