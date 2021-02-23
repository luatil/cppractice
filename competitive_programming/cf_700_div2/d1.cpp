#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = a; i < n; i++)
#define ll long long 

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

int main()
{
	int n; cin >> n;
	vector<int> v(n+1);
	//jfor(auto& el : v) cin >> el;
	for(int i = 1; i <= n; ++i )
		cin >> v[i];

	vector<int> pos(n+1, n+1), next(n+1);
	for(int i = n; i >= 0; --i)
	{
		next[i] = pos[v[i]];
		pos[v[i]] = i;
	}

	int up_index = 0, down_index = 0, total = 0;
	for(int i = 1; i <= n; ++i)
	{
		int up = v[up_index];
		int down = v[down_index];
		int curr = v[i];
		if(curr == up)
		{
			total += (curr != down);
			down_index = i;
		}
		else if(curr == down)
		{
			total += (curr != up);
			up_index = i;
		}
		else if(next[up_index] < next[down_index])
		{
			total += (curr != up);
			up_index = i;
		}
		else 
		{
			total += (curr != down);
			down_index = i;
		}
	}

	cout << total;
}
