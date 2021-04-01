CC=g++
FLAGS=-std=c++11 -Wall -Wextra -Wshadow -Wno-sign-conversion -ggdb3

t: t.cpp
	$(CC) $(FLAGS) -o $@ $^

%: %.cpp
	$(CC) $(FLAGS) -o $@ $^
