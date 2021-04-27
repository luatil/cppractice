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
	vector<int>v(5, 0);
	REP(i, n)
	{
		cin >> temp;
		v[temp]++;
	}
	v[1] -= min(v[3], v[1]);
	v[2] += v[1] / 2;
	v[1] = v[1] % 2;
	const auto total =  v[4] + v[3] + (v[2])/2 + 1 *(v[2]%2==1||v[1]==1);
	cout << total << "\n";
}
