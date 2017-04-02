CC=g++

all:hello  detar deposit autotest autotest2
.PHONE:clean all


#hello:hello.cpp 
#	$(CC) hello.cpp -o hello

autotest2:autotest2.cpp
	$(CC) $< -o $@
autotest:autotest.cpp
	$(CC) $< -o $@
deposit:deposit.cpp
	$(CC) $< -o $@
detar:detar.cpp
	$(CC) $< -o $@
hello:hello.cpp
	$(CC) $< -o $@

clean:
	rm hello 
