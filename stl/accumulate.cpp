#include <iostream>
#include <numeric>
#include <vector>
#include <functional> // plus{}

auto get_vector_sum_1a(std::vector<int> v) -> int 
{
	auto x = std::accumulate(std::cbegin(v), std::cend(v), 0);
	return x;
}

auto get_vector_sum_1b(std::vector<int> v) -> int 
{
	auto x = std::accumulate(std::cbegin(v), std::cend(v), 0, std::plus{});
	return x;
}

auto get_vector_product_1a(std::vector<int> v) -> int
{
	auto x = std::accumulate(std::cbegin(v), std::cend(v), 1, std::multiplies{});
	return x;
}

int main()
{
	std::vector<int> v = {1, 2, 3, 4};
	std::cout << "The sum is: "<< get_vector_sum_1b(v) << std::endl;
	std::cout << "The product is: "<< get_vector_product_1a(v) << std::endl;
	return 0;
}
