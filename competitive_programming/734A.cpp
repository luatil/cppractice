#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
	int n;
	string s;
	cin >> n >> s;
	const auto anton = count_if(all(s), [](auto e){ return e == 'A'; });
	const auto danik = n - anton; 
	if(anton > danik) cout << "Anton";
	else if(danik > anton) cout << "Danik";
	else cout << "Friendship";
}
