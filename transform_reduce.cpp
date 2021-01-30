#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

// Given a vector coins, find the minimum difference between two elements
// 1 4 2 -> 1
// 3 3 0 -> 0

auto min_diff(vector<int>& c) -> int 
{
	sort(begin(c), end(c));
	return transform_reduce(++cbegin(c), cend(c), cbegin(c), 
		numeric_limits<int>::max(),
		[](auto a, auto b) { return min(a, b); },
		std::minus{});
}

void call_min_diff() 
{
	vector<int> v1{1, 4, 2};
	cout << "The minimun difference of v1 is: " << min_diff(v1) << endl;
	vector<int> v2{3, 3, 0};
	cout << "The minimun difference of v2 is: " << min_diff(v2) << endl;
}

void ex1()
{
	vector<int> v{1, 2, 3};
	vector<int> u{2, 3, 4};

	auto r1 = transform_reduce(cbegin(v), cend(v), cbegin(u), 0);
	cout << "The inner product of v and u is: " << r1 << endl;

	auto r2 = transform_reduce(cbegin(v), cend(v), cbegin(u), 0, 
							plus{}, equal_to<>());
	cout << "Number of pairwise matches between v and u: " << r2 << endl;

	auto r3 = sqrt(transform_reduce(cbegin(v), cend(v), 0,
				   plus{}, [](auto e) {return e * e; }));
	cout << "The sqrt of the sum of the square of the elements of v is: " << r3 << endl;
	auto r4 = sqrt(transform_reduce(cbegin(v), cend(v), cbegin(v), 0));
	cout << "The sqrt of the sum of the square of the elements of v is: " << r4 << endl;

}


int main()
{
	call_min_diff();

	return 0;
}
