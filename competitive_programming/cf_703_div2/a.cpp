#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

void solve()
{
    int n; cin >> n;
    vector<long long> v(n);

    for(auto& el : v) cin >> el;

    partial_sum(all(v), v.begin());

    for(int i = 0; i < n; i++)
    {
        if(v[i] < (i*(i+1))/2) 
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
