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

    void build(int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int minimum(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return inf;
        }
        if(l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(minimum(v*2, tl , tm, l, min(r, tm)) 
               , minimum(v*2+1, tm+1, tr, max(l, tm+1), r));
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
            t[v] = min(t[v*2], t[v*2+1]);
        }
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
        cin >> k >> a >> b;
        if(k == 1) {
            tree.update(1, 0, n-1, a-1, b);
        } else {
            cout << tree.minimum(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
}