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

// Greddy problem
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	REP(i, n) 
		cin >> v[i];
	sort(all(v), greater<int>());
	const auto total = accumulate(all(v), 0.0);
	auto my_total = 0;
	auto i = 0;
	while(2 * my_total <= total) {
		my_total += v[i];
		i++;
	}
	cout << i;

}
