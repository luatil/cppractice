#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 1;
    map<int, int> mp;
    // fast slow two pointers
    for(int f = 0, s = 0; f < n; f++) {
        s = max(mp[v[f]], s);
        ans = max(ans, f - s + 1);
        mp[v[f]] = f + 1;
    }
    cout << ans << '\n';
    
}