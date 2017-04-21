CC=g++


.PHONY:all clean
all: vector printstar printstarN function global array convert   inline

vector:vector.cpp
	$(CC) -std=gnu++11  vector.cpp -o vector
printstar:printstar.cpp
	$(CC) -std=gnu++11  printstar.cpp -o printstar
printstarN:printstarN.cpp
	$(CC) -std=gnu++11  printstarN.cpp -o printstarN
function:function.cpp
	$(CC) -std=gnu++11  function.cpp -o function
global:global.cpp
	$(CC) -std=gnu++11  global.cpp -o global
array:array.cpp
	$(CC) -std=gnu++11 $< -o $@
convert:convert.cpp
	$(CC) -std=gnu++11 $< -o $@
convert:convert.cpp
	$(CC) -std=gnu++11 $< -o $@
test2:print1.cpp print2.cpp
	$(CC) -std=gnu++11 print1.cpp print2.cpp  -o $@
inline:inline.cpp
	$(CC) -std=c++11 inline.cpp   -o $@
clean:
	rm vector printstar
