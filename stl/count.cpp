#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template<class I, class T>
auto get_count(I f, I l, T const& val) -> int
{
	return std::reduce(f, l, 0, [val](auto a, auto b){return a + (b == val); } );
}

int main()
{
	std::vector<int> v = {1, 2, 3, 1, 2, 2};
	std::cout << "The number of ones in v is: "<< std::count(std::cbegin(v), std::cend(v), 1) << std::endl;
	std::cout << "The number of twos in v is: "<< get_count(std::cbegin(v), std::cend(v), 2) << std::endl;
	return 0;
}
