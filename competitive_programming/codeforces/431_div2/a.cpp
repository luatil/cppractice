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
	string s; cin >> s;
	vector<short> qs, qas;
	int total_qs = 0, total_qas = 0;
	
	transform(all(s), back_inserter(qs), [&](auto e)
			{
				if(e == 'A') return total_qs;
				if(e == 'Q') total_qs++; 
				return 0;
			});


	const auto total = inner_product(all(s), begin(qs), 0, plus<>(), 
									[&](auto a, auto b)
									{
										if(a == 'Q') return total_qas;
										if(a == 'A') total_qas += b;
										return 0;
									});
	//print(qs);
	//print(qas);
	cout << total;
}


int main()
{
	solve();
}
