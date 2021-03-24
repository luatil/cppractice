#include <iostream>
#include <numeric>
#include <algorithm>
#include "print.cpp"

using namespace std;

void simple_example1()
{
	std::vector<int> v(10); 
	std::iota(v.begin(), v.end(), 0);

	std::cout << "The vector before adjacent_difference: ";
	print(v);

	std::adjacent_difference(v.begin(), v.end(), v.begin());

	std::cout << "The vector after adjacent_difference:  ";
	print(v);
}

// Given a vector coins, find the minimum difference between two elements
// 1 4 2 -> 1
// 3 3 0 -> 0

auto min_diff(std::vector<int>& coins) -> int 
{
	std::sort(coins.begin(), coins.end());
	std::vector<int> diff(coins.size());
	std::adjacent_difference(coins.cbegin(), coins.cend(), diff.begin());
	return *std::min_element(diff.cbegin() + 1, diff.cend());
}

// I think this is solvable with inclusive_scan
auto inclusive_scan_min_diff(std::vector<int>& coins) -> int
{
	std::sort(coins.begin(), coins.end());
	std::vector<int> diff(coins.size());
	std::inclusive_scan(coins.cbegin(), coins.cend(), diff.begin(), 
						[](auto e) {  });
	return *std::min_element(diff.cbegin() + 1, diff.cend());
}

//-----------------------------------------------------------------------

void call_min_diff()
{
	std::vector<int> v1{1, 4, 2};
	std::cout << "The minimun difference of v1 is: " << min_diff(v1) << endl;
	std::vector<int> v2{3, 3, 0};
	std::cout << "The minimun difference of v2 is: " << min_diff(v2) << endl;
}

// Given a vector, count the adjacent equal elements
// 1 1 4 3 2 2 -> 2 
// 1 2 3 4 5 -> 0

auto count_adj_equals(std::vector<int> const& v) -> int 
{
	vector<int> d(v.size(), 0);
	std::adjacent_difference(std::cbegin(v), std::cend(v), std::begin(d));
	return count_if(std::cbegin(d) + 1, std::cend(d),
			[](auto e) { return e == 0; });
}

void call_count_adj_equals()
{
	std::vector<int> v{1, 1, 4, 3, 2, 2};
	std::cout << "The number of adjcent equal elements of v is:" << count_adj_equals(v) << endl;

	std::vector<int> u{1, 2, 3, 4, 5};
	std::cout << "The number of adjcent equal elements of u is:" << count_adj_equals(u) << endl;
}

int main()
{
	simple_example1();
	return 0;
}
