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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vi a(n);
    for(auto&el : a) cin >> el;

    while(m--) {
        int k, l, r; cin >> k >> l >> r;
        if(k == 1) {
            // add fib(i-l+1) for each ai where l <= i <= r
            // This part kind complicates it a little bit
        } else if(k == 2) {
            // ouput the sum of ai where l <= i <= r modulo MOD
        }
    }
}
