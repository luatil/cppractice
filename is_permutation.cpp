#include <iostream>
#include <algorithm> // is_permutation

void simple_example1()
{
	 std::vector<int> v1{1, 3, 2, 4, 5, 6};
	 std::vector<int> v2{3, 1, 2, 5, 4, 6};

	 const auto is_perm = std::is_permutation(v1.cbegin(), v1.cend(), v2.cbegin());

	 std::cout << is_perm << "\n";
}

int main()
{
	simple_example1();

}
