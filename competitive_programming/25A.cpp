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

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	for(auto &el : v) cin >> el;

	int even = 0, odd = 0, last_odd = -1, last_even = -1, i=0;
	while(i < n)
	{
		if((v[i]&1) == 0)
		{
			even++;
			last_even=i;
		}
		else 
		{
			odd++;
			last_odd=i;
		}
		i++;
	}

	cout << (even == 1 ? last_even : last_odd) + 1;
}

int main()
{
	solve();
}
