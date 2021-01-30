#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print(T v)
{
	for(const auto& el : v) std::cout << el << " ";
	std::cout << std::endl;
}

void example1()
{
	std::vector<int> v{3, 2, 1, 1, 1, 8, 9, 10};
	print(v);
	// sort first 3 elements from v
	std::partial_sort(v.begin(), v.begin() + 3, v.end());
	print(v);
}

// Get the 3 biggest numbers from v
void example2()
{
	std::vector<int> v{3, 2, 1, 1, 1, 8, 9, 10};
	print(v);
	// sort first 3 elements from v
	std::partial_sort(v.begin(), v.begin() + 3, v.end(),
					  [](auto a, auto b) {return a > b; });

	std::vector<int> ans;
	std::copy(v.cbegin(), v.cbegin() + 3, std::back_inserter(ans));

	print(ans);
}

int main()
{
	example2();
}
