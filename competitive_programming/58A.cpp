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
	auto it = s.begin() - 1;
	const string hello = "hello";
	for(const auto& el : hello)
		it = find(it+1, s.end(), el);
	cout << (it == s.end() ? "NO" : "YES");
}
