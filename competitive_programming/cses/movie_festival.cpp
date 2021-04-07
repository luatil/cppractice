#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    int n; cin >> n;
    vector<pair<ll, ll> > a(n);
    for(int i =0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a), [](auto x, auto y) { return x.second < y.second;});

    ll ans = 1;
    ll curr = a[0].second;
    for(int i = 1; i < n; i++) {
        if(a[i].first >= curr) {
            ans++;
            curr = a[i].second;
        }
    }

    cout << ans << '\n';
}