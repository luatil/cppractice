#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pi> v;
    v.reserve(n);
    int l, r;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        v.push_back({l, r});
    }

    sort(all(v));

    ll ans = 0;
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        curr += v[i].f;
        ans += v[i].s - curr;
    }

    cout << ans << '\n';
} 