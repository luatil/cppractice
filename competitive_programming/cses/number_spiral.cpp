#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(int y, int x) {
    if(x > y) {
        if(x % 2 == 1) {
            return f(x, x) + x - y;
        }
        if(x % 2 == 0) {
            return f(x, x) + y - x;
        }
    }
    if(y > x) {
        if(y % 2 == 1) {
            return f(y, y) + x - y;
        }
        if(y % 2 == 0) {
            return f(y, y) + y - x;
        }
    }
    return 1 + x * (x - 1);
}

void solve() 
{
    ll y, x; cin >> y >> x;
    cout << f(y, x) << '\n';
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}