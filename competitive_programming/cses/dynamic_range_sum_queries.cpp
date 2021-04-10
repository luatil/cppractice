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

struct SegmentTree {
    vector<int> bit;  // binary indexed tree
    int n;

    SegmentTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    SegmentTree(vector<int> a) : SegmentTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    SegmentTree tree(v);
    int k; int a; int b;
    while(q--) {
        cin >> k >> a >> b;
        if(k == 1) {
            tree.add(a-1, b - tree.sum(a-1, a-1));
        } else {
            cout << tree.sum(a-1, b-1) << '\n';
        }
    }
}