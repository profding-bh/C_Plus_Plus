CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all: test test2

doubleArray.o:doubleArray.cpp
	$(CC) $(CFLAGS) -c $< # get doubleArray.o file
test:test.cpp doubleArray.o
	$(CC) $< doubleArray.o $(CFLAGS) -o $@
	
rational.o:rational.cpp
	$(CC) $(CFLAGS) -c $< # get rational.o file
test2:test2.cpp rational.o
	$(CC) $< rational.o $(CFLAGS) -o $@
	
clean:
	rm test	 doubleArray.o rational.o
