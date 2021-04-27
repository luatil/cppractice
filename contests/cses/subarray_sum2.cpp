#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x; cin >> n >> x;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll prefix_sum = 0;
    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for(const auto&el : v) {
        prefix_sum += el;
        ans += mp[prefix_sum - x];
        mp[prefix_sum]++;
    }

    cout << ans << '\n';
}