#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

bool special(ll a, ll b) 
{
    return (a/b) == (a%b);
}

void solve()
{
    ll x, y; cin >> x >> y;
    ll ans = 0;
    for(int i = 2; i <= x; ++i)
    {
        for(int j = 2; j <= y; j++)
        {
            if(special(i, j))
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--)
        solve();
}
