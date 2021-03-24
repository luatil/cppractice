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
	std::vector<int> v{2, 3, 4, 1};

	print(v);
	// sort in ascending order
	std::sort(v.begin(), v.end());
	print(v);
}

void sort_just_the_first_two_elements()
{
	std::vector<int> v{3, 2, 1, 4};

	print(v);
	std::sort(v.begin(), v.begin() + 2);
	print(v);
}

void sort_strings()
{
	std::vector<std::string> v{"mouse", "dog", "cat", "ant", "moth", "elephant"};

	print(v);
	sort(v.begin(), v.end());
	print(v);
}

void sort_strings_by_length_example()
{
	std::vector<std::string> v{"mouse", "dog", "cat", "ant", "moth", "elephant"};

	auto sort_by_length = [] (const auto& a, const auto& b) { return a.size() < b.size(); };

	print(v);
	std::sort(v.begin(), v.end(), sort_by_length);
	print(v);
}

int main()
{
	example1();
	sort_just_the_first_two_elements();
	sort_strings();
	sort_strings_by_length_example();
}
