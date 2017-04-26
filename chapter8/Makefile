CC=g++

.PHONY:all clean 
all: test1 struct

test1:test1.cpp
	$(CC) -std=gnu++11 test1.cpp -o test1
struct:struct.cpp
	$(CC) -std=gnu++11 struct.cpp -o struct
clean:
	rm test1  struct
