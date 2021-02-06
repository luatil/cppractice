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
	string s;
	cin >> s;
	vector<int> v;
	v.reserve(s.size());
	transform(s.begin(), s.end()-1, s.begin()+1, back_inserter(v), [](auto a, auto b){return a == b;}  );
	v.push_back(0);
	partial_sum(all(v), v.begin());
	int n;
	cin >> n;
	int l, r;
	REP(i, n)
	{
		cin >> l >> r;
		cout << v[r-2] - v[l-2]*(l!=1) << "\n";
	}

}
