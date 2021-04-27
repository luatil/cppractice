#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

ll min_num(ll a, ll b) {

    if(a == b) {
        return a * 10;
    }

    if(a % 10 == 9) {
        while(b < a) {
            b *= 10;
        }
        return b;
    }

    ll na = a, nb = b;
    while(na > 0) {
        if(na == b) {
            return a + 1;
        }
        na /= 10;
    }

    while(b < a) {
        b *= 10;
    }

    return b;

}

void solve(int index)
{
    int n; cin >> n;
    ll ans = 0;
    ll a, b;
    cin >> a;
    for(int i = 1; i < n; i++) {
        cin >> b; 

        if(b > a) {
            a = b;
            continue;
        } else {
            ll nb = min_num(a, b);
            ans += (int)log10(nb) - (int)log10(b);
            a = nb;
        }

    }
    cout << "Case #" << index << ": " << ans << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}