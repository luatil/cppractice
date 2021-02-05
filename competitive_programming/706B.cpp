#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

int main()
{
	int n;
	cin >> n;
	int temp;
	vector<int> v;
	v.reserve(100'002);
	REP(i, n)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(all(v));
	int q;
	cin >> q;
	int coins;
	REP(i, q)
	{
		cin >> coins;
		cout << distance(v.begin(), upper_bound(all(v), coins)) << "\n";
	}
}
