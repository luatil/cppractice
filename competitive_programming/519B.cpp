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
	int t1=0, t2=0, t3=0;
	int temp;
	REP(i, n)
	{
		cin >> temp;
		t1 += temp;
	}
	REP(i, n-1)
	{
		cin >> temp;
		t2 += temp;
	}
	REP(i, n-2)
	{
		cin >> temp;
		t3 +=temp;
	}
	cout << t1 - t2 << "\n";
	cout << t2 - t3 << "\n";
}
