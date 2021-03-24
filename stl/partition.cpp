#include <iostream>
#include <algorithm>
using namespace std;

auto separate_even_from_odds(vector<int>& A)
{
	partition(begin(A), end(A), [](auto e) { return e % 2 == 0 ;});

	return A;
}

void separate_even_from_odds_ex1()
{
	vector<int> v{1, 3, 2, 4, 3, 5, 4};
	for(auto el : v) { cout << el << " " ;};
	cout << endl;
	separate_even_from_odds(v);
	for(auto el : v) { cout << el << " " ;};
	cout << endl;
}

int main()
{
	separate_even_from_odds_ex1();
	return 0;
}
