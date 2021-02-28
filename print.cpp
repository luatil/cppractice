#include <iostream>

template <typename T> 
void print(T v)
{
	for (const auto& el : v) std::cout << el << " ";
	std::cout << "\n";
}
