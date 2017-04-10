CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all:enum enum2 enum3

enum:enum.cpp
	$(CC) $< $(CFLAGS) -o $@
enum2:enum2.cpp
	$(CC) $< $(CFLAGS) -o $@
enum3:enum3.cpp
	$(CC) $< $(CFLAGS) -o $@
clean:
	rm enum enum2 enum3
