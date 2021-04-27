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


const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;

const int MAXN = 1e5 * 2 + 55; 
vi adj[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi values(n);
    for(auto&el : values) cin >> el;
    int a, b;
    for(ll i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    int temp;
    for(ll i = 0; i < q; i++) {
        cin >> temp;
        if(temp == 1) {
            int s, x; cin >> s >> x;
            // Change the value of node s to x
        } else if(temp == 2) {
            int s; cin >> s;
            // Calculate the values in the subtree of node s
            // Output the answer
        }
    }
}
