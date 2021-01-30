#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;


int main()
{
	vector<int> v1{0, 1, 2, 3, 4};
	vector<int> v2{5, 4, 2, 3, 1};

	auto r1 = inner_product(cbegin(v1), cend(v1), cbegin(v2), 0);
	cout << "The inner product of v1 and v2 is: " << r1 << endl;

	auto r2 = inner_product(cbegin(v1), cend(v1), cbegin(v2), 0, 
							plus{}, equal_to<>());
	cout << "Number of pairwise matches between v1 and v2: " << r2 << endl;

	auto r3 = sqrt(inner_product(cbegin(v1), cend(v1), cbegin(v1), 0.0));
	cout << "The sqrt of the sum of the square of the elements of v1 is: " << r2 << endl;

	return 0;
}
