#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    ll n, m, x; 
    cin >> n >> m >> x;
    ll right=0, down=0;
    ll i = 1;

    ll l = 1, r = x / n; 
    while(l * n < x - 1 && l + 1 < r)
    {
        ll mid = (l + r)/2;
        if(mid * n > x - 1) r = mid;
        else l = mid;
    }

    l--;
    i+= l*n;
    right += l;

    while(i <= x)
    {
        i += n;
        right++;
    }

    if(i != x)
    {
        i -= n;
        right--;
        down = x - i;
    }
    cout << right + down * m + 1<< '\n';

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}