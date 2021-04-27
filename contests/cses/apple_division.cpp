#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto&el : v) cin >> el;
    ll total = 0;
    for(auto&el : v) total += el;

    ll mini = numeric_limits<ll>::max() / 4;
    for(int mask = 0; mask < (1 << n); mask++) {
        ll sub = 0;
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                sub += v[i];
            }
        }
        mini = min(mini, abs(total - 2*sub));
    }
    cout << mini << '\n';
}