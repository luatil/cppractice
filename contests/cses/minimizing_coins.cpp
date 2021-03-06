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
    int n, x; cin >> n >> x;
    vi v(n);
    for(auto&el : v) cin >> el;

    vi memo(x+1, inf);
    memo[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - v[j] >= 0) {
                memo[i] = min(memo[i], 1 + memo[i-v[j]]);
            }
        }
    }
    cout << (memo[x] >= inf ? -1 : memo[x]) << '\n';
}