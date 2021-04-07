#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
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
    ll n, x; cin >> n >> x;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll curr = 0;
    ll ans = 0;
    ll fast = 0, slow = 0;
    while(slow < n || fast < n) {
        if(curr < x && fast == n) {
            break;
        }
        if(slow < n && curr == x) {
            ans++;
            curr -= v[slow];
            slow++;
        } else if(slow < n && curr > x) {
            curr -= v[slow];
            slow++;
        } else if(fast < n && curr < x) {
            curr += v[fast];
            fast++;
        }
    }

    cout << ans << '\n';
}