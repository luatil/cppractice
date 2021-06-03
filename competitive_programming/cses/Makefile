CC=g++
FLAGS=-Wall -Wextra -Wshadow -Wno-sign-conversion -ggdb3

%: %.cpp
	$(CC) $(FLAGS) -o $@.out $^

clean: 
	rm *.out
