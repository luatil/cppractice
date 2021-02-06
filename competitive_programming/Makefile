CC=g++
FLAGS=-std=c++17 -Wall -Wextra -Wshadow -Wno-sign-conversion -g

t: t.cpp
	$(CC) $(FLAGS) -o $@ $^

%: %.cpp
	$(CC) $(FLAGS) -o $@ $^
