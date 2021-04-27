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
int dist[N];
int parent[N];


void bfs(int s) {

    queue<int> q;
    dist[s] = 0;
    parent[s] = -1;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        for(const auto&el : adj[curr]) {
            if(!visited[el]) {
                q.push(el);
                visited[el] = true;
                dist[el] = dist[curr] + 1;
                parent[el] = curr;
            }
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

    bfs(1);

    if(visited[n]) {
        cout << dist[n] + 1 << '\n';
        int curr = n;
        vector<int> v;
        while (curr != -1) {
            v.push_back(curr);
            curr = parent[curr];
        }
        reverse(all(v));
        for(const auto&el : v) cout << el << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}