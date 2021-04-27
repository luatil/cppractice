#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

using vi = vector<ll>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mkp make_pair

const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;
const int MAXN = 1e5+44;

ll n, t[2*MAXN];

void build() {
    for(int i = n-1; i > 0; --i) {
        t[i] = t[i<<1] + t[i<<1|1];
    }
}

ll sum(int l, int r) {
    ll ans = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) ans += t[l++];
        if(r&1) ans += t[--r];
    }
    return ans;
}

void set_to(int p, ll value) {
    for(t[p += n] = value; p > 1; p >>=1) t[p>>1] = t[p] + t[p^1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> t[i+n];
    }

    build();

    while(m--) {
        int qt; 
        cin >> qt;
        if(qt == 1) {
            int i, v; 
            cin >> i >> v;
            set_to(i, v);
        } else if(qt == 2) {
            int l, r;
            cin >> l >> r;
            ll ans = sum(l, r);
            cout << ans << '\n';
        }
    }

}
