CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all: test test2 complex test3

construct.o:construct.cpp
	$(CC) $(CFLAGS) -c $< # get construct.o file
test:test.cpp construct.o
	$(CC) $< construct.o $(CFLAGS) -o $@
	
createanddestroy.o:createanddestroy.cpp
	$(CC) $(CFLAGS) -c $< # get createanddestroy.o file
test2:test2.cpp createanddestroy.o
	$(CC) $< createanddestroy.o $(CFLAGS) -o $@	
	
complex:complex.cpp complex.h
	$(CC) $<  $(CFLAGS) -o $@	
	
test3:test3.cpp 
	$(CC) $<  $(CFLAGS) -o $@	
clean:
	rm  test2 construct.o createanddestroy.o 
