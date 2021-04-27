#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;
ll a[SIZE];

void solve()
{
    int n, q, k; cin >> n >> q >> k;
    REP(i, n)
    {
        cin >> a[i];
    }

    int l, r;
    while(q--)
    {
        cin >> l >> r; // 1 shifted to the right
        int curr = 0;
        ll ans = a[l-1] - 1;

        ans += (((a[r-1] - a[l-1]) -1) - (r - l - 1)) * 2 ;


        ans += (k - a[r-1]);

        cout << ans << '\n';
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
