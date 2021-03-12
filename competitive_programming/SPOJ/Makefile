CC=g++
FLAGS=-std=c++17 -Wall -Wextra -Wshadow -Wno-sign-conversion -ggdb3
BINS=acode_alphacode.out

all: $(BINS)

%.out: %.cpp
	$(CC) $(FLAGS) -o $@ $^

clean: 
	rm $(BINS)
