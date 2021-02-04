#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)

auto distinct(string s) -> bool
{
	sort(all(s));
	return adjacent_find(all(s)) == s.end();
}


int main()
{
	int n;
	cin >> n;
	string s;
	while(true) {
		n++;
		s = to_string(n);
		if(distinct(s)) 
		{
			cout << s;
			return 0;
		}

	}
}
