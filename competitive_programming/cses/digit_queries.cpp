#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mpow(ll a, ll i) {
    if(i == 0) return 1;
    if(i == 1) return a;
    return a * mpow(a, i-1);
}


ll dlen(ll n) {
    ll ans = min(n, 9LL);
    n -= 9;
    ll a = 9LL;
    ll b = 1LL;
    for(ll i = 2; n >= 0; i++, b *= 10) {
        ans += min(n, a * b * 10) * i;
        n-= a * b * 10;
    }
    return ans;
}

ll upper_b(ll n) {
    ll ans = 256; 
    while(dlen(ans) < n) {
        ans *= 2;
    }
    return ans;
}

int solve() 
{
    int q; cin >> q;
    while(q--) {
        ll n; cin >> n;
        ll l = 0, r = upper_b(n);
        while(l + 1 <= r) {
            ll mid =(l + r) / 2;
            if(dlen(mid) >= n) {
                r = mid;
            }
            else {
                l = mid + 1;
            }

        }
        string str = to_string(r);
        cout << str[str.size() - (dlen(r) - n) -1] << '\n';
    }
}

int main() {
    solve();
}