CC=g++

all:hello  call_in initialize user-define
.PHONE:clean all


hello:hello.cpp 
	$(CC) hello.cpp -o hello
call_in:call_in.cpp
	$(CC) call_in.cpp -o call_in
initialize:initialize.cpp
	$(CC) initialize.cpp  -std=c++11 -o initialize
user-define:user-define.cpp
	$(CC) user-define.cpp  -std=c++11 -o user-define
clean:
	rm hello call_in initialize user-define
