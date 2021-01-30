CC=g++
FLAGS= -std=c++17

%: %.cpp
	$(CC) -o $@.out $^
