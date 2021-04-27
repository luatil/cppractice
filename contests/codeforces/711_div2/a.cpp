#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long 

ll dsum(ll x) {
    ll ans = 0;
    while(x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve()
{
    ll n; cin >> n;
    // maximum of 3 steps dsum is logn
    while(__gcd(n, dsum(n)) == 1) {
        n++;
    }
    cout << n << '\n';
}

void test() 
{
    for(ll i = 1; i < 100; i++) {
        cout << i << ": " << __gcd(i, dsum(i)) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    test();
    // int t; cin >> t;
    // while(t--)
    //     solve();
}