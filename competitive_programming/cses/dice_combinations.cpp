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
const int N = 1e6+55;

ll memo[N];

ll dp(int n) {
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(memo[n] != -1) return memo[n];

    memo[n] = 0;
    for(int i = 1; i <= 6; ++i) {
        memo[n] = (memo[n] + dp(n-i)) % MOD;
    }

    return memo[n];
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(memo, -1, sizeof(memo));
    int n; cin >> n;
    cout << dp(n) << '\n';
}