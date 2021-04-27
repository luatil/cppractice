#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

#define int long long
using vi = vector<int>;
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

const int MAXN =2*1e5+55;
// const int MAXN = 10;

struct SegmentTree {
    int n, t[4*MAXN];
    vector<int> a;

    SegmentTree(const vector<int>& b) {
        copy(all(b), back_inserter(a));
    }

    ll fun(ll x, ll y) {
        return x ^ y;
    }

    const ll identity = 0;

    void build(int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = fun(t[v*2], t[v*2+1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return identity;
        }
        if(l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return fun(query(v*2, tl , tm, l, min(r, tm)),
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    ll iquery(int l, int r) {
        return query(1, 0, a.size()-1, l, r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if(tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm) {
                update(v*2, tl, tm, pos, new_val);
            } else {
                update(v*2+1, tm+1, tr, pos, new_val);
            }
            t[v] = fun(t[v*2], t[v*2+1]);
        }
    }

    void iupdate(int pos, ll new_val) {
        update(1, 0, a.size()-1, pos, new_val);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    SegmentTree tree(v);
    tree.build(1, 0, n-1);
    int k; int a; int b;
    while(q--) {
        cin >> a >> b;
        cout << tree.iquery(a-1, b-1) << '\n';
    }
}
