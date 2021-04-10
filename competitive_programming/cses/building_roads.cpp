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

const int N = 1e5+5, M = 2*1e5+5;
bool visited[N];
vi adj[N];

void dfs(int i) {
    if(!visited[i]) {
        visited[i] = true;
        for_each(all(adj[i]), dfs);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    vector<int> vans;
    dfs(1);
    for(int i = 2; i <= n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
            vans.push_back(i);
        }
    }
    cout << ans << '\n';
    for(const auto&el : vans) {
        cout << 1 << ' ' << el << '\n';
    }
}