CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all:array find bifind

array:array.cpp
	$(CC) $< $(CFLAGS) -o $@

find:find.cpp
	$(CC) $< $(CFLAGS) -o $@
bifind:find.cpp
	$(CC) $< $(CFLAGS) -o $@

clean:
	rm array
