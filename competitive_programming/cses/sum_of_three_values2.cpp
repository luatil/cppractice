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

// This aproach uses 2 value sum n times
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

    for(int i = 0; i < n; i++) {
        int nx = x - v[i].f;
        int l = 0, r = n-1;
        while(l < r) {
            if(l == i) {
                l++;
            }
            if(r == i) {
                r--;
            }
            if(l!=r && v[l].first + v[r].first == nx)  {
                cout << v[l].second + 1 << ' ' << v[r].second + 1 << ' ' << v[i].second+1<< '\n';
                return 0;
            }
            else if(v[l].first + v[r].first > nx)  { 
                r--;
            }
            if(v[l].first + v[r].first < nx)  {
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}