#include <numeric>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

auto generate_n_fibonacci(int n) -> vector<int>
{
	vector<int> fib(n, 1);
	transform(cbegin(fib),
			  cend  (fib) - 2,
			  cbegin(fib) + 1,
			  begin (fib) + 2, 
			  plus{});
	return fib;
}

void fib_ex1()
{
	vector<int> fib10 = generate_n_fibonacci(10);
	for(auto el : fib10) { cout << el << " "; }
	cout << endl;
}

auto to_lower_case(string s) -> string
{
	transform(begin(s), 
			  end(s),
			  begin(s),
			  ::tolower);
	return s;
}

void to_lower_case_ex1()
{
	string s{"HeLlO"};
	cout << s << endl;
	cout << to_lower_case(s) << endl;
}

// Given a vector of integers in non-decreasing order, return a vector with the squares of the elements also in non-decreasing order

auto sorted_squares(vector<int> & A)
{
	transform(
		begin(A),
		end(A),
		begin(A),
		[] (auto e) { 
			return e * e; 
		});

	sort(begin(A), end(A));

	return A;
}

void sorted_squares_ex()
{
	vector<int> v{-2, -1, -1, 0, 33, 40, 55};
	for(auto el : v)
	{
		cout << el << " ";
	}
	cout << endl;
	sorted_squares(v);
	for(auto el : v)
	{
		cout << el << " ";
	}
	cout << endl;
}


int main()
{
	sorted_squares_ex();
	return 0;
}
