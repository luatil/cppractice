#include <iostream>
#include <algorithm>
#include <numeric>

template <typename T>
void print(T v)
{
	for (auto & el : v) std::cout << el << " ";
	std::cout << "\n";
}

void call_example1()
{
	std::vector<int> v(10);
	std::iota(v.begin(), v.end(), 1); // not very efficient for this example
	print(v);

	std::make_heap(v.begin(), v.end());
	print(v);

}

void call_example2()
{
	std::vector<double> v(10);
	std::iota(v.begin(), v.end(), 1); // not very efficient for this example
	print(v);

	std::make_heap(v.begin(), v.end());
	print(v);

	v.push_back(8.88);
	print(v);

	std::push_heap(v.begin(), v.end());
	print(v);

}

void call_example3()
{
	std::vector<double> v(10);
	std::iota(v.begin(), v.end(), 1); // not very efficient for this example
	print(v);

	std::make_heap(v.begin(), v.end());
	print(v);

	std::pop_heap(v.begin(), v.end());
	print(v);

}

void call_example4()
{
	std::vector<double> v(10);
	std::iota(v.begin(), v.end(), 1); // not very efficient for this example
	std::reverse(v.begin(), v.end()); // not very efficient for this example
	print(v);

	std::sort_heap(v.begin(), v.end());
	print(v);

}

int main()
{
	call_example4();
}
