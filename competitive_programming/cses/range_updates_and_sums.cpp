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

const int MAXN = 2*1e5+55;

ll t[4*MAXN], lazy[4*MAXN];
bool lazy2[4*MAXN];

void build(const vi& a, int i, int l, int r) {
    if(l == r) {
        t[i] = a[l];
    } else {
        int mid = (l+r)/2;
        build(a, 2*i, l, mid);
        build(a, 2*i+1, mid+1, r);
        t[i] = t[2*i] + t[2*i+1];
        lazy[i] = 0;
        lazy2[i] = 0;
    }
}

void push(ll i, ll tl, ll tr) {
    if(tl != tr) {
        if(lazy2[i]) {
            lazy2[2*i] = lazy2[i];
            lazy2[2*i+1] = lazy2[i];
            lazy[2*i] = lazy[i];
            lazy[2*i+1] = lazy[i];
        } else {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
    } 
    t[i] = (lazy2[i] ? 0 : t[i]);
    t[i] += lazy[i] * (tr - tl + 1);
    lazy[i] = 0;
    lazy2[i] = 0;
}

void increase(ll l, ll r, ll val, ll i, ll tl, ll tr) {

    push(i, tl, tr);
    
    if(tl > r || tr < l) {
        return;
    } else if(tl >= l && tr <= r) {
        lazy[i] += val;
        push(i, tl, tr);
    } else {
        int mid = (tl+tr)/2;
        increase(l, r, val, 2*i, tl, mid);
        increase(l, r, val, 2*i+1, mid+1, tr);
        t[i] = t[2*i] + t[2*i+1];
    }
}

void set_to(ll l, ll r, ll val, ll i, ll tl, ll tr) {

    push(i, tl, tr);
    
    if(tl > r || tr < l) {
        return;
    } else if(tl >= l && tr <= r) {
        lazy2[i] = true;
        lazy[i] = val;
        push(i, tl, tr);
    } else {
        int mid = (tl+tr)/2;
        set_to(l, r, val, 2*i, tl, mid);
        set_to(l, r, val, 2*i+1, mid+1, tr);
        t[i] = t[2*i] + t[2*i+1];
    }
}    

ll sum(ll l, ll r, ll i, ll tl, ll tr) {

    push(i, tl, tr);
    
    if(tl > r || tr < l) {
        return 0;
    } else if(tl >= l && tr <= r) {
        return t[i];  
    } else {
        int mid = (tl+tr)/2;
        ll left = sum(l, r, 2*i, tl, mid);
        ll right = sum(l, r, 2*i+1, mid+1, tr);
        return left + right;
    }
}
    



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v; v.resize(n);
    for(auto&el : v) cin >> el;

    build(v, 1, 0, n-1);

    while(q--) {
        int qt; cin >> qt;
        if(qt == 1) {
            // Increase value in range [a, b] by x
            ll a, b, x; cin >> a >> b >> x;
            a--; b--;
            increase(a, b, x, 1, 0, n-1);
        } else if(qt == 2) {
            // Set each value in range [a, b] to x
            ll a, b, x; cin >> a >> b >> x;
            a--; b--;
            set_to(a, b, x, 1, 0, n-1);
        } else if(qt == 3) {
            ll a, b; cin >> a >> b;
            // Calculate the sum of values in range [a, b]
            a--; b--;
            ll ans = sum(a, b, 1, 0, n-1);
            cout << ans << '\n';
        }
    }
}
