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

struct SegTree {
    vi a, t;
    int n;

    SegTree(const vector<ll>&b) {
        a = b;
        this->n = a.size();
        t.resize(4*n+1);
        build(1, 0, n-1);
    }

    void build(int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if(l > r) 
            return;
        if(l == tl && r == tr) {
            t[v] += add;
        } else {
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, l, min(r, tm), add);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        }
    }

    ll get(int v, int tl, int tr, int pos) {
        if(tl == tr)
            return t[v];
        int tm = (tl + tr) /2;
        if(pos <= tm)
            return t[v] + get(v*2, tl, tm, pos);
        else 
            return t[v] + get(v*2+1, tm+1, tr, pos);
    }

    void increase(int l, int r, int val) {
        update(1, 0, n-1, l, r, val);
    }

    ll query(int k) {
        return get(1, 0, n-1, k);
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n);
    for(auto&el : v) cin >> el;

    SegTree range(v);

    int temp;
    while(q--) {
        cin >> temp;
        if(temp == 1) {
            // Increase [a, b] by val 
            int a, b, val; cin >> a >> b >> val;
            a--; b--;
            range.increase(a, b, val);
        } else {
            // Query value at k
            int k; cin >> k;
            k--;
            cout << range.query(k) << '\n';
        }
    }
}
