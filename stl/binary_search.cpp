#include <iostream>
#include <vector>
#include <algorithm>
#include "print.cpp"

void simple_example1()
{
	std::vector<int> v = {1, 3, 3, 7, 9};
	// check if 3 is in v
	auto flag = std::binary_search(v.cbegin(), v.cend(), 3);
	std::cout << "3 is " << (flag ? "" : "not ") << "in v\n";
}

void simple_example2()
{
	std::vector<int> v = {1, 3, 3, 7, 9};
	// get the position of the first element >= than 3 
	auto it = std::lower_bound(v.cbegin(), v.cend(), 3);
	auto index = distance(v.cbegin(), it); // the same as (it - v.cbegin())
	std::cout << "The first element bigger or equal to 3 is at index: " << index << "\n";
}

void simple_example3()
{
	std::vector<int> v = {1, 3, 3, 7, 9};
	// get the position of the first element bigger than 3
	auto it = std::upper_bound(v.cbegin(), v.cend(), 3);
	auto index = distance(v.cbegin(), it); 
	std::cout << "The first element bigger than 3 is at index: " << index << "\n";
}

void simple_example4()
{
	std::vector<int> v = {1, 3, 3, 7, 9};
	// what if there is no element bigger or equal?
	auto it = std::lower_bound(v.cbegin(), v.cend(), 10);
	auto index = distance(v.cbegin(), it); 
	std::cout << "The value 10 should be put on the index: " << index << "\n";
}


int main() 
{
	std::vector<int> index = {0, 1, 2, 3, 4};
	std::vector<int> v = {1, 3, 3, 7, 9};
	print(index);
	print(v);
	simple_example1();
	simple_example2();
	simple_example3();
	simple_example4();
}
