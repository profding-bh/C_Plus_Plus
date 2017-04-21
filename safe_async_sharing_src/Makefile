CC=g++
CFLAGS=-std=c++11

.PHONE:clean all
all:  safe_async_sharing_example

safe_async_sharing_example:safe_async_sharing_example.cpp
	$(CC) $< $(CFLAGS) -o $@
clean:
	rm safe_async_sharing_example
