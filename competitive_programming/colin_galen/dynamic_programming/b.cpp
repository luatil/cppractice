#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
 
const int SIZE = 2e5 + 7;
ll a[SIZE];
ll n, m, k, q, l, r, x, y, z;
string s, t;
ll ans = 0;
 
void solve()
{
    cin >> n >> k;
    cin >> s;
 
    bool typeable[26] = {0}; // true if you can type it
 
    for(ll i = 0; i < k; i++) 
    {
        char c;
        cin >> c;
        typeable[c - 'a'] = 1;
    }
 
    for(ll i = 0; i < n; i++) 
    {
        a[i] = (typeable[s[i] - 'a'] ? 1 : 0);
    }
 
    ll f[n+1];
    f[0] = 0;
 
    for(ll i = 0; i <= n; i++ )
    {
        f[i+1] = (a[i] == 0 ? 0 : f[i] + 1);
        ans += f[i+1];
    }
 
    cout << ans << '\n';
 
}
 
 
int main()
{
    solve();
}
