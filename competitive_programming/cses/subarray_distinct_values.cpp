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
    ll n, k; cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll ans = 0;
    unordered_map<int, int> mp;
    mp.reserve(n);
    int fast = 0, slow = 0; 
    while(fast < n) {
        // If the count of distinct numbers in the current window is 
        // smaller or equal to k I insert the current on fast on the window
        if(mp.size() <= k) {
            mp[v[fast]]++;
        }

        // Decrease the window until I encounter a new valid one
        while(mp.size() > k) {
            mp[v[slow]]--;
            if(mp[v[slow]] == 0) {
                mp.erase(v[slow]);
            }
            slow++;
        }

        ans += fast - slow + 1;
        fast++;
    }

    cout << ans << '\n';
}