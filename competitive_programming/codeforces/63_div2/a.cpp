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
	int x, y, z;
	int tx, ty, tz;
	tx = ty = tz = 0;
	REP(i, n)
	{
		cin >> x >> y >> z;
		tx += x;
		ty += y;
		tz += z;
	}
	cout << (tx == 0 && ty == 0 && tz == 0 ? "YES" : "NO");
}
