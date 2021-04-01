#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, a, n) for(int i = a; i < n; i++)

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

// This one is with linear space, usefull if you want
// the indexes
auto max_contiguous_subarray_sum(const vector<int>& v) -> int
{
	vector<int> memo;
	memo.reserve(v.size());
	partial_sum(v.begin(), v.end(), back_inserter(memo), [](auto a, auto b)
			      {return max(b, b+a);});
	print(memo);
	return *max_element(memo.begin(), memo.end());
}

void simple_example1()
{
	vector<int> v{1, -3, 2, 1, -1};
	const auto ans = max_contiguous_subarray_sum(v);
	cout << ans << "\n";
}

void simple_example2()
{
	vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
	print(v);
	const auto ans = max_contiguous_subarray_sum(v);
	cout << ans << "\n";
}

auto max_contiguous_subarray_sum_constant_space(const vector<int>& v) -> int
{
	int max_sum = numeric_limits<int>::min();
	int curr_sum = 0;
	for(const auto& el : v)
	{
		curr_sum = max(curr_sum+el, el);
		max_sum = max(max_sum, curr_sum);
	}
	return max_sum;
}

void simple_example1b()
{
	vector<int> v{1, -3, 2, 1, -1};
	const auto ans = max_contiguous_subarray_sum_constant_space(v);
	cout << ans << "\n";
}

void simple_example2b()
{
	vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
	print(v);
	const auto ans = max_contiguous_subarray_sum_constant_space(v);
	cout << ans << "\n";
}

int main()
{
	simple_example1();
	simple_example1b();
	simple_example2();
	simple_example2b();
}

