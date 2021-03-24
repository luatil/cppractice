#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void print(T v)
{
	for(const auto& el : v) std::cout << el << " ";
	std::cout << std::endl;
}

template<typename T>
void print_for_bosses(T v)
{
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void simple_example1()
{
	std::vector<int> v;
	print(v);
	std::cout << v.capacity() << std::endl;
}

void simple_example2()
{
	std::vector<int> v;
	v.reserve(10);
	print(v);
	std::cout << v.capacity() << std::endl;
}

void simple_example3()
{
	std::vector<int> v(10);
	print(v);
	std::cout << v.capacity() << std::endl;
}

void simple_example4()
{
	std::vector<int> v(10, 2);
	print_for_bosses(v);
	std::cout << v.capacity() << std::endl;
}

void simple_example5()
{
	std::vector<double> v = {10.4, 2};
	print(v);
	std::cout << v.capacity() << std::endl;
}

void simple_example6()
{
	std::vector v = {10.4, 2.};
	print(v);
}

void simple_example7()
{
	std::vector<int> v{2, 2, 2, 2};
	v.insert(v.cbegin() + 1, 42);
	print(v);
}


int main()
{
//	simple_example1();
//	simple_example2();
//	simple_example3();
//	simple_example4();
//	simple_example5();
//	simple_example6();
	simple_example7();
}
