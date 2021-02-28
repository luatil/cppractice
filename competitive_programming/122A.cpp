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
	string s;
	for(int i = 4; i <= n; ++i)
	{
		if(n%i==0)
		{
			s = to_string(i);
			if(all_of(all(s), [](auto e) { return e == '4' || e == '7'; })) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}
