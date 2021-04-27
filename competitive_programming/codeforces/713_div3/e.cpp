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
 
const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;
 
ll min_val(ll l, ll r, ll n) {
    ll k = (r - l + 1);
    ll ans = k * (k+1)/2;
    return ans;
}
 
ll max_val(ll l, ll r, ll n) {
    ll k = (r - l + 1);
    ll ans = k * (2*n+1-k) / 2; 
    return ans;
}
 
void solve(int index)
{
    ll n, l, r, s; cin >> n >> l >> r >> s;
 
    if(s < min_val(l, r, n) || s > max_val(l, r, n)) {
        cout << "-1\n";
        return;
    }
 
    vi simple(n);
    vi st;
    iota(all(simple), 1);
 
    int nnr = r;
    while(s > 0) {
        ll a = min_val(l, r, n);
        st.push_back(s-a);
        s = a;
        r--;
    }
    r = nnr;
 
    // if(s == 1) {
    //     st.push_back(1);
    // }
 
    reverse(all(st));
 
    vi real_simple;
    set_difference(simple.begin(), simple.end(), st.begin(), st.end(), back_inserter(real_simple));
 
    for(int i = 1; i <= n; i++) {
        if(i < l || i > r) {
            cout << real_simple.back() << ' ';
            real_simple.pop_back();
        } else {
            cout << st.back() << ' ';
            st.pop_back();
        }
    }
 
    cout << '\n';
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}