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
	cout << (find_if(all(s), [](auto e){ return e == 'H' || e == 'Q' || e == '9'; }) == s.end() ? "NO" :"YES");
}
