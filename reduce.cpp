#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional> // plus{}

auto get_vector_sum_1a(std::vector<int> v) -> int 
{
	auto x = std::reduce(std::cbegin(v), std::cend(v));
	return x;
}

auto get_vector_sum_1b(std::vector<int> v) -> int 
{
	auto x = std::reduce(std::cbegin(v), std::cend(v), 0, std::plus{});
	return x;
}

auto get_vector_product_1a(std::vector<int> v) -> int
{
	auto x = std::reduce(std::cbegin(v), std::cend(v), 1, std::multiplies{});
	return x;
}

// Implementing count with reduce
template<class I, class T>
auto get_count(I f, I l, T const& val) -> int
{
	return std::reduce(f, l, 0, [val](auto a, auto b){return a + (b == val); } );
}

// Implementing any_of with reduce
template<class I, class P>
auto my_any_of(I f, I l, P p) -> bool 
{
	return std::reduce(f, l, false, [p](auto a, auto b) { return a || p(b); });
}



int main()
{
	std::vector<int> v = {1, 2, 3, 4};
	std::cout << "The sum is: "<< get_vector_sum_1b(v) << std::endl;
	std::cout << "The product is: "<< get_vector_product_1a(v) << std::endl;

	std::vector<int> v2 = {1, 2, 3, 1, 2, 2};
	std::cout << "The number of ones in v2 is: "<< std::count(std::cbegin(v2), std::cend(v2), 1) << std::endl;
	std::cout << "The number of twos in v2 is: "<< get_count(std::cbegin(v2), std::cend(v2), 2) << std::endl;

	std::cout << "The vector v does " <<  (std::any_of(std::cbegin(v), std::cend(v), [](auto e) { return e == 4; }) ? "" : "not ") << "contains 4" << std::endl;
	std::cout << "The vector v2 does " << (my_any_of(std::cbegin(v2), std::cend(v2), [](auto e) { return e == 4; }) ? "" : "not ") << "contains 4" << std::endl;




	return 0;
}
