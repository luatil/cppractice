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

const int N = 1e5+55, M = 2*N+55;
vector<int> adj[N];
bool visited[N];
int color[N];
bool flag = true;

#define RED 1
#define BLUE 2

void dfs(int i, int c) {
    if(!visited[i] && flag) {
        visited[i] = true;
        color[i] = c;
        for(auto&el : adj[i]) {
            if(color[el] == c) {
                flag = false;
                return;
            }
            if(c == RED) dfs(el, BLUE);
            if(c == BLUE) dfs(el, RED);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; 
    cin >> n >> m;
    int a, b;
    for(int j = 0; j < m; j++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        dfs(i, RED);
    }

    if(flag) {
        for(int i = 1; i <= n; i++) {
            cout << color[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

}