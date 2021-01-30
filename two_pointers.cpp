#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print(T v)
{
	for(const auto& el : v) std::cout << el << " ";
	std::cout << std::endl;
}

// Given an sorted vector of integers and a number k, check if there exists two numbers that sum up to k

auto check_if_two_numbers_sum_to_k(std::vector<int> sorted_v, int k) -> bool 
{
	auto left = sorted_v.begin();
	auto right = sorted_v.end() - 1;

	while(left != right) {
		if(*left + *right == k) return true;
		if(*left + *right > k) right--;
		if(*left + *right < k) left++;
	}

	return false;
}


void test1()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 8, 9};
	std::cout << check_if_two_numbers_sum_to_k(v, 9) << std::endl;
}

void test2()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 8, 9};
	std::cout << check_if_two_numbers_sum_to_k(v, 19) << std::endl;
}

void test3()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6, 8, 9};
	std::cout << check_if_two_numbers_sum_to_k(v, 3) << std::endl;
}


int main()
{
	test1();
	test2();
	test3();
}
