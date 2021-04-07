#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; ll t; cin >> n >> t;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll lo = 0; ll hi = 1e18; ll ans = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (mid / v[i]);
            if(sum >= t) {
                break;
            }
        }
        if(sum >= t) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}