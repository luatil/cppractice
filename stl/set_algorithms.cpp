#include <iostream>
#include <vector>
#include <algorithm>
#include "print.cpp"

void simple_example1()
{
	std::vector<int> v1{1, 2, 5, 6, 8, 9, 10};
	std::vector<int> v2{0, 2, 3, 4, 7, 8, 10};

	std::vector<int> res;

	std::set_intersection(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), std::back_inserter(res));

	print(res); // 2 8 10
}

void simple_example2()
{
	std::vector<int> v1{1, 2, 5, 6, 8, 9, 10};
	std::vector<int> v2{0, 2, 3, 4, 7, 8, 10};

	std::vector<int> res;

	std::set_union(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), std::back_inserter(res));

	print(res); // 0 1 2 3 4 5 6 7 8 9 10
}

void simple_example3()
{
	std::vector<int> v1{1, 2, 5, 6, 8, 9, 10};
	std::vector<int> v2{0, 2, 3, 4, 7, 8, 10};

	std::vector<int> res;

	std::set_symmetric_difference(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), std::back_inserter(res));

	print(res); // 0 1 3 4 5 6 7 9  
}

int main()
{
	simple_example1();
	simple_example2();
	simple_example3();
}
