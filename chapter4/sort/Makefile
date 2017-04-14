CC=gcc
CPP=g++
CFLAGS=-std=c99
CPPFLAGS=-std=c++11

.PHONE:clean all
all:sortint sortchar sortdouble sortstruct sortstr sort sorttwodemen

sortint:sortint.c
	$(CC) $< $(CFLAGS) -o $@
sortchar:sortchar.c
	$(CC) $< $(CFLAGS) -o $@
sortdouble:sortdouble.c
	$(CC) $< $(CFLAGS) -o $@
sortstruct:sortstruct.c
	$(CC) $< $(CFLAGS) -o $@
sortstr:sortstr.c
	$(CC) $< $(CFLAGS) -o $@
sort:sort.cpp
	$(CPP) $< $(CPPFLAGS) -o $@
sorttwodemen:sorttwodemen.cpp
	$(CPP) $< $(CPPFLAGS) -o $@
clean:
	rm  sortchar sortdouble
