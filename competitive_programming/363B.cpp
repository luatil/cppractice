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

int main()
{
	int n, k; 
	cin >> n >> k;
	vector<int> v(n);
	REP(i, 0, n)
		cin >> v[i];
	v.push_back(0);
	partial_sum(rbegin(v), rend(v), rbegin(v));
	transform(v.begin(), v.end()-k-1, v.begin() + k, v.begin(), [](auto a, auto b){ return a - b; });
	cout << distance(v.begin(), min_element(v.begin(), v.end()-k)) + 1<< "\n";
}
