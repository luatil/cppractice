#include <iostream>
#include <algorithm>
#include <vector>
#include "print.cpp"

void simple_example1()
{
	std::vector<int> v = {1, 4, 3, 3};
	// print all permutations of v
	std::sort(v.begin(), v.end());
	do {
		print(v);
	} while(std::next_permutation(v.begin(), v.end()));
}

int main()
{
	simple_example1();
}
