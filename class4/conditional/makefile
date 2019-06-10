all: hello goodmorning

# Build hello with no macros defined
hello: hello.c
	gcc hello.c --std=c11 -Wall -pedantic -o hello

# Build goodmorining with "MORNING" defined
goodmorning: hello.c
	gcc hello.c --std=c11 --Wall pedantic -D MORNING -o goodmorning

# make clean to remove executables
clean:
	rm -f *.o *.exe *~
