#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

void solve()
{
    long long n, u, v; cin >> n >> u >> v;
    vector<long long> obstacles(n);
    vector<long long> diff(n);

    for(auto& el : obstacles) cin >> el;

    auto it = find(all(obstacles), 0);

    adjacent_difference(obstacles.begin(), it, diff.begin());

    // for(auto& el : obstacles) cout << el << ' ';
    // cout << '\n';

    for(auto& el : diff) el = abs(el);

    const long long largest_gap = *max_element(diff.begin()+1, diff.end());

    if(largest_gap == 0) cout << min(u + v, 2*v) << '\n';
    if(largest_gap == 1) cout << min({u, v}) << '\n';
    if(largest_gap >= 2) cout << 0 << '\n';

    //cout << "Largest Gap "  <<  largest_gap << '\n';
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
}
