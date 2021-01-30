CC=g++
FLAGS= -std=c++17

%: %.cpp
	$(CC) $(FLAGS) -o $@.out $^
