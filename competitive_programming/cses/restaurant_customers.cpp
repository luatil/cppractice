#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    int n; cin >> n;
    vector<ll> a(n), d(n);
    for(int i =0; i < n; ++i) {
        cin >> a[i] >> d[i];
    }

    sort(all(a)); sort(all(d));

    ll l = 0, r = 0;
    ll curr = 0;
    ll ans = -1;
    while(l < n && r < n) {
        if(a[l] < d[r]) {
            curr++;
            l++;
        }
        else {
            r++;
            curr--;
        }
        ans = max(ans, curr);
    }

    cout << ans << '\n';
}