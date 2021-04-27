#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    int n; cin >> n;
    vector<ll> p;
    p.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    ll median = p[n/2];
    ll ans = 0;
    for(const auto&el : p) {
        ans += abs(median-el);
    }

    cout << ans << '\n';
}