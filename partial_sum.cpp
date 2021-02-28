#include <iostream>
#include <numeric>
#include <vector>
#include "print.cpp"
using namespace std;

void simple_example1()
{
 	vector<int> v{1, 1, 1, 1, 1};
	vector u(5, 0);
	partial_sum(cbegin(v), cend(v), begin(u));
	cout << "The vector v is: ";
	print(v);
	cout << endl;
	cout << "The partial sum of v is: ";
	print(u);
	cout << endl;
}

void simple_example2()
{
	vector<int> v{1, 2, 3, 4, 5};
	vector u(5, 0);
	partial_sum(cbegin(v), cend(v), begin(u));
	cout << "The vector v is: ";
	print(v);
	cout << endl;
	cout << "The partial sum of v is: ";
	print(u);
	cout << endl;
}



int main()
{
	simple_example1();
	simple_example2();
	return 0;
}
