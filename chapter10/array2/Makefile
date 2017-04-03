CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all: test 

doubleArray.o:doubleArray.cpp
	$(CC) $(CFLAGS) -c $< # get doubleArray.o file
test:test.cpp doubleArray.o
	$(CC) $< doubleArray.o $(CFLAGS) -o $@
clean:
	rm test	 
