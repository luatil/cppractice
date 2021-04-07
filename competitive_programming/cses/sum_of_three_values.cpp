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

const ll inf = numeric_limits<ll>::max() / 4;

// This aproach searches for the 3rd value with binary search
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<pi> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].f;
        v[i].s = i;
    }

    sort(all(v));

    int curr = 0;
    for(int i = 0; i < n; i++) {
        curr = v[i].f;
        if(curr >= x) {
            break;
        }
        for(int j = i+1; j < n; j++) { 
            curr += v[j].f;
            if(curr >= x) {
                break;
            }
            auto it = lower_bound(v.begin() + j+1, v.end(), make_pair(x-curr, -1));
            if(curr + (*it).f == x) {
                cout << v[i].s+1 << ' ' << v[j].s+1 << ' ' << (*it).s+1 << '\n';
                return 0;
            }
            curr -= v[j].f;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}