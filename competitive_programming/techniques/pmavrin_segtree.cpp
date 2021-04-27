#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

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

// Let's code a simple segment tree with point set to update and sum
struct SegTree {
    vector<int> a, t, lo, hi, delta, seto;
    int n;

    SegTree(const vector<int>& b) {
        a = b;
        this->n = b.size();
        t.resize(4*n+1);
        lo.resize(4*n+1);
        hi.resize(4*n+1);
        delta.resize(4*n+1);
        seto.resize(4*n+1);
        build(1, 0, n-1);
    }

    void build(int i, int l, int r) {
        lo[i] = l;
        hi[i] = r;
        if(l==r) {
            t[i] = a[l];
        } else {
            int mid = (l+r)/2;
            build(2*i, l, mid);
            build(2*i+1, mid+1, r);
            t[i] = t[2*i] + t[2*i+1];
        }
    }

    int sum(int l, int r) {
        return sum(1, l, r);
    }

    int sum(int i, int l, int r) {
    
        // Out of range
        if(lo[i] > r || hi[i] < l) return 0;
        // Completely inside the range
        if(lo[i] >= l && hi[i] <= r) {
            return t[i] + seto[i] * (hi[i] - lo[i] + 1);
        }

        prop(i);

        int left_sum = sum(2*i, l, r);
        int right_sum = sum(2*i+1, l, r);

        update(i);

        return left_sum + right_sum;
    }

    void update(int i) {
        t[i] = t[2*i] + t[2*i+1];
        t[i] += seto[2*i] * (hi[2*i] - lo[2*i] + 1);
        t[i] += seto[2*i] * (hi[2*i+1] - lo[2*i+1] + 1);
    }

    void prop(int i) {
        seto[2*i] = seto[i];
        seto[2*i+1] = seto[i];
        seto[i] = 0;
    }

    void add(int l, int r, int val) {
        add(1, l, r, val);
    } 

    void add(int i, int l, int r, int val) {
        // Out of range
        if(lo[i] > r || hi[i] < l) return;
        // Completely inside the range
        if(lo[i] >= l && hi[i] <= r) {
            delta[i] += val;
            return;
        }

        prop(i);

        add(2*i, l, r, val);
        add(2*i+1, l, r, val);

        update(i);
    }

    void set_to(int l, int r, int val) {
        set_to(1, l, r, val);
    }

    void set_to(int i, int l, int r, int val) {
        // Out of range
        if(lo[i] > r || hi[i] < l) return;
        // Completely inside the range
        if(lo[i] >= l && hi[i] <= r) {
            seto[i] = val;
            t[i] = 0;
            return;
        }

        prop(i);

        set_to(2*i, l, r, val);
        set_to(2*i+1, l, r, val);

        update(i);
    }

    void print() {
        int mask = 1;
        for(int i = 0; i < 4*n+1; i++) {
            if(i == mask) {
                mask <<= 1;
                cout << '\n';
            }
            cout << t[i] << ' ';
        }
    }
};


void test() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    SegTree seg(v);
    // seg.print();
    cout << seg.sum(0, 2) << '\n'; // 6
    cout << seg.sum(0, 0) << '\n'; // 1
    cout << seg.sum(0, 7) << '\n'; // 36
    seg.add(0, 2, 10);
    cout << seg.sum(0, 2) << '\n'; // 36 
    cout << seg.sum(0, 0) << '\n'; // 11 
    cout << seg.sum(0, 7) << '\n'; // 66 
    seg.add(0, 2, -10);
    cout << seg.sum(0, 2) << '\n'; // 36 
    cout << seg.sum(0, 0) << '\n'; // 11 
    cout << seg.sum(0, 7) << '\n'; // 66 
}

void test2() {
    vector<int> v{0, 0, 0, 0, 0, 0, 0, 0};
    SegTree seg(v);
    cout << seg.sum(0, 7) << '\n'; // 0;
    seg.set_to(0, 7, 1);
    cout << seg.sum(0, 7) << '\n'; // 8;
    seg.set_to(0, 7, 0);
    seg.set_to(0, 7, 2);
    cout << seg.sum(0, 7) << '\n'; // 16;
    seg.set_to(0, 1, 4); 
    cout << seg.sum(0, 1) << '\n'; // 8;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    // test();
    test2();
}
