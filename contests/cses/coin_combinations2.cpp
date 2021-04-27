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

    vi memo(x+1);
    memo[0] = 1;

    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= x; i++) {
            if(memo[i] != 0) {
                if(i+v[j] <= x) {
                    memo[i+v[j]] = (memo[i+v[j]] + memo[i]) % MOD;
                }
            }
        }
    }


    cout << memo[x] << '\n';
}