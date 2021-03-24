/*
 * CppCon 2019: Conor Hoekstra “Algorithm Intuition (part 1 of 2)”
 *  
 * 
 * */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Problem, given an array of integers, find the difference between the minimun and maximum

// solution 1a n^2
auto solve1a() -> int { 
	std::vector v{2, 1, 3, 5, 4};
	auto ans = std::numeric_limits<int>::min();
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v.size(); ++j) {
			ans  = std::max(ans, abs(v[i] - v[j]));
		}
	}
	return ans;
}

// solution 1a' c++11 // adds range based for loops 
auto solve1b() -> int {
	std::vector v{2, 1, 3, 5, 4};
	auto ans = std::numeric_limits<int>::min();
	for(auto a : v) {
		for(auto b : v) {
			ans  = std::max(ans, abs(a - b));
		}
	}
	return ans;
}

// solution 2a n log n 
auto solve2a() -> int {
	std::vector v{2, 1, 3, 5, 4};
	std::sort(std::begin(v), std::end(v));
	return *--std::end(v) - *std::begin(v);
}

// solution 2b
auto solve2b() -> int {
	std::vector v{2, 1, 3, 5, 4};
	std::sort(std::begin(v), std::end(v));
	return *std::rbegin(v) - *std::begin(v);
}

// solution 2c
auto solve2c() -> int {
	std::vector v{2, 1, 3, 5, 4};
	std::sort(std::begin(v), std::end(v));
	return v.back() - v.front();
}


// solution 3a 
auto solve3a() -> int {
	std::vector v{2, 1, 3, 5, 4};
	auto a = std::numeric_limits<int>::max();
	auto b = std::numeric_limits<int>::min();
	for (auto e : v) {
		a = std::min(a, e);
		b = std::max(b, e);
	}
	return b - a;
}

// solution 3b 
auto solve3b() -> int {
	std::vector v{2, 1, 3, 5, 4};
	auto a = *std::min_element(begin(v), end(v));
	auto b = *std::max_element(begin(v), end(v));
	return b - a;
}

// solution 3c (C++20 Ranges)
//auto solve3c() -> int {
//	std::vector<int> v{2, 1, 3, 5, 4};
//	auto a = *std::min_element(v);
//	auto b = *std::max_element(v);
//	return b - a;
//}

auto solve4a() -> int {
	std::vector<int> v{2, 1, 3, 5, 3};
	auto p = std::minmax_element(begin(v), end(v));
	return *p.second - *p.first;
}

auto solve4b() -> int {
	std::vector<int> v{2, 1, 3, 5, 3};
	auto [a, b] = std::minmax_element(begin(v), end(v));
	return *b - *a; 
}

// solution 4c (C++20)
//auto solve4c() -> int {
//	std::vector<int> v{2, 1, 3, 5, 3};
//	auto [a, b] = std::minmax_element(v);
//	return *b - *a; 
//}

auto solve4d() -> int {
	std::vector<int> v{2, 1, 3, 5, 3};
	auto [a, b] = std::minmax_element(cbegin(v), cend(v));
	return *b - *a; 
}

int main()
{
	constexpr auto smaller = std::numeric_limits<int>::min();
	std::cout << solve4b() << std::endl;
	return 0;
}
