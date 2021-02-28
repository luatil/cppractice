#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void print(T v)
{
	for(const auto& el : v) std::cout << el << " ";
	std::cout << std::endl;
}

void rotate_example1()
{
	std::vector<int> v{1, 2, 3, 4, 5};

	print(v);
	std::rotate(v.begin(), v.begin() + 2, v.end());
	print(v);
}

void rotate_copy_example1()
{
	std::vector<int> const v{1, 2, 3, 4, 5};
	std::vector<int> u(5);

	print(u); // 0 0 0 0 0 
	std::rotate_copy(v.cbegin(), v.cbegin() + 2, v.cend(), u.begin());
	print(u); // 3 4 5 1 2 
}

int main()
{
	rotate_example1();
	rotate_copy_example1();
}
