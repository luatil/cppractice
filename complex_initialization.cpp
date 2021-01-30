#include <iostream>
#include <cstdlib>

void example1()
{
	const int i = std::rand();
	std::string s;
	switch (i % 4) {
		case 0: 
			s = "long string is mod 0";
			break;
		case 1:
			s = "long string is mod 1";
			break;
		case 2: 
			s = "long string is mod 2";
			break;
		case 3:
			s = "long string is mod 3";
			break;
	}
}

void refactor_example1()
{
	const int i = std::rand();
	const std::string s = [&]() {
		switch (i % 4) {
			case 0: 
				return "long string is mod 0";
			case 1:
				return "long string is mod 1";
			case 2: 
				return "long string is mod 2";
			case 3:
				return "long string is mod 3";
		}
	}();

}

int main()
{
	refactor_example1();

}
