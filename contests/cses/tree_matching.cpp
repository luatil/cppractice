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

const int MAXN = 1e5 * 2 + 55;
vi adj[MAXN];
bool visited[MAXN];
bool color[MAXN];
#define RED 1
#define BLUE 0
int blues = 0, reds = 0;
int color_num[2];

void dfs(int i, int c) {
    c ^= 1;
    visited[i] = true;
    for(auto&el : adj[i]) {
        if(!visited[el]) {
            color_num[c]++;
            dfs(el, c);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a, b;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    color_num[RED] = 1;
    color[1] = RED;
    dfs(1, RED);

    cout << min(color_num[0], color_num[1]) << '\n';
}
