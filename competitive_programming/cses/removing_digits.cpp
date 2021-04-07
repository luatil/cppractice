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
bool visited[N];

ll dp(ll n) {
    if(n < 0) return inf;
    if(n == 0) return 0;
    if(visited[n]) {
        return memo[n];
    }
    visited[n] = true; 
    int x = n;
    while(x > 0) {
        memo[n] = min(memo[n], 1 + dp(n - (x % 10)));
        x /= 10;
    }
    return memo[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    memset(memo, 1, sizeof(memo));
    memset(visited, 0, sizeof(visited));
    cout << dp(n) << '\n';
}