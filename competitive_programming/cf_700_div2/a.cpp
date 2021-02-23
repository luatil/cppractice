#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define FORE(i,a,n) for(int i = a; i < n; i++)

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

void solve()
{
	string s;
	cin >> s;
	int temp = s.size();
	REP(i, temp) 
	{
		if(i%2==0)
			s[i] = (s[i] == 'a' ? 'b' : 'a');
		else
			s[i] = (s[i] == 'z' ? 'y' : 'z');
	}
	cout << s << "\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
