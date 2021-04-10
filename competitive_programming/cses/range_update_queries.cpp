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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vi prefix;
    prefix.reserve(n+2);
    adjacent_difference(all(v), back_inserter(prefix));

    int temp, k, a, b, u;
    while(q--) {
        cin >> temp;
        if(temp == 1) {
            cin >> a >> b >> u;
            prefix[a] += u;
            prefix[b+1] -= u;
        } else {
            cin >> k;
            partial_sum(prefix.begin(), prefix.begin() + k + 1, prefix.begin());
            cout << prefix[k] << '\n';
            adjacent_difference(prefix.begin(), prefix.begin() + k + 1, prefix.begin());
        }
    }
}