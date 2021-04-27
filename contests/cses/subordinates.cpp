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

const int MAXN = 2 * 1e5 + 55;
vi adj[MAXN];
int tree_size[MAXN];
bool visited[MAXN];

int dfs(int i) {
    visited[i] = true;
    ll ans = 0;
    for(auto&el : adj[i]) {
        if(!visited[el]) {
            ans += 1 + dfs(el);
        }
    }
    return tree_size[i] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a;
    for(int i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        cout << tree_size[i] << ' ';
    }
    cout << '\n';
}
