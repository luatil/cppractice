#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const ll inf = numeric_limits<long long>::max() / 4;

void solve()
{
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &el : v) cin >> el;

    // 

    if(n == 1) 
    {
        cout << 0 << '\n';
        return;
    }

    auto it = adjacent_find(v.begin(), v.end(), [](auto x, auto y){ return x <= y;});
    if(it == v.end())
    {
        if(n == 2) cout << 0 << '\n';
        else 
        {
            ll m = v.front() + 1;
            ll c = v[1] + 1;
            vector<ll> sol(n);
            sol[0] = v.front();
            for(int i = 1; i < n; i++)
            {
                sol[i] = (sol[i-1] + c) % m;
            }
            if(sol == v)
            {
                cout << 0 << '\n';
                return;
            }
            cout << -1 << '\n';
        }
        return;
    }
    ll c = *(next(it)) - *it;
    auto it2 = adjacent_find(v.begin(), v.end(), [](auto x, auto y){ return x > y;});
    ll m;
    if(it2 == v.end()) // vector is always increasing
    {
        m = inf;
    }
    else 
    {
        m = *it2 + c - *(next(it2));
    }

    vector<ll> sol(n);
    sol[0] = v.front();
    for(int i = 1; i < n; i++)
    {
        sol[i] = (sol[i-1] + c) % m;
    }

    if(sol == v && v[0] < m)
    {
        if(m == inf) 
        {
            cout << 0 << '\n';
        }
        else 
        {
            cout << m << ' ' << c << '\n';
        }
        return;
    }
    cout << -1 << '\n';
    return;


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
