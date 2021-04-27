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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k; cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    oset<int> st(a.begin(), a.begin() + k + 1);

    ll old_m = *st.find_by_order((k + 1) / 2 - 1);
    ll d = 0;
    for(int i = 0; i < k; i++) d += (abs(a[i] - old_m));

    cout << d << ' ';

    for(int i = 0; i < n - k; i++) {
        st.erase(st.find_by_order(st.order_of_key(a[i])));
        st.insert(a[i+k]);
        ll m = *st.find_by_order((k + 1) / 2 - 1);
        d = d + abs(m - a[i + k]) - abs(old_m - a[i]);
        if(k % 2 == 0) d -= (m - old_m);
        old_m = m;
        cout << d << ' ';
    }
    cout << endl;
}