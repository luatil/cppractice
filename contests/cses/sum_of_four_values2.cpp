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

// This uses unordered map instead
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<pi> v;
    v.reserve(n);
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back({temp, i+1});
    }

    sort(all(v));
    unordered_map<int, vector<pair<int, int>>> mp;
    mp.reserve(n);

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = v[i].f + v[j].f;

            if(sum >= x) { break; };

            if(mp.count(x - sum)) {
                vector<pair<int, int>> possible = mp[x-sum];
                for(const auto&el : possible) {
                    auto[a, b] = el;
                    if(a != v[i].s && b != v[j].s && a != v[j].s && b != v[i].s)  {
                        cout << v[i].s << ' ' << v[j].s << ' ' << a << ' ' << b << '\n';
                        return 0;
                    }
                }
            }

            mp[sum].push_back({v[i].s, v[j].s});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}