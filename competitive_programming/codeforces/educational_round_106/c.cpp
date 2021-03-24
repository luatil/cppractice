#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}

void solve()
{
    int n; cin >> n;
    vector<int> cost(n);
    for(auto& el : cost) cin >> el;

}

void drive()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

int main()
{
    drive();
}
