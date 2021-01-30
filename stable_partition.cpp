#include <iostream>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums)
{
	stable_partition(begin(nums),
			         end(nums),
					 [](auto e) { return e != 0; });
}

void move_zeroes_ex()
{
	vector<int> v{1, 3, 0, 0, 3, 0, 4};
	for(auto el : v) { cout << el << " " ;};
	cout << endl;
	moveZeroes(v);
	for(auto el : v) { cout << el << " " ;};
	cout << endl;
}

int main()
{
	move_zeroes_ex();
	return 0;
}
