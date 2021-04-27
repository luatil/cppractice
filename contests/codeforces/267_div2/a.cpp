#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
	int n;
	cin >> n;
	int p, q;
	int total = 0;
	REP(i, n) {
		cin >> p >> q;
		total += ((q - p) >= 2);
	}
	cout << total;
}
