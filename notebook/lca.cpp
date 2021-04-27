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


struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n*2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m*4);
        build(1, 0, m-1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for(auto&el : adj[node]) {
            if(!visited[el]) {
                dfs(adj, el, h+1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if(b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b+e)/2;
            build(node<<1, b, mid);
            build(node<<1|1, mid+1, e);
            int l = segtree[node<<1], r = segtree[node<<1|1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if(b > R || e < L) return -1;
        if(b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if(left == -1) return right;
        if(right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if(left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj;
    adj.resize(n+1);
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    LCA data(adj);

    while(m--) {
        int k; cin >> k;
        vi query(k);
        for(int i = 0; i < k; i++) {
            cin >> query[i];
            query[i]--;
        }

        sort(all(query), [&](auto a, auto b){ return data.height[a] > data.height[b];});

        int flag = true;

        for(int i = 1; i < k; i++) {
            int lowest_common_ancestor = data.lca(query[i-1], query[i]);
            if(lowest_common_ancestor != query[i]) {
                if(data.height[query[i-1]] - data.height[lowest_common_ancestor] > 1 && 
                   data.height[query[i]] - data.height[lowest_common_ancestor] > 1) {
                   cout << "NO\n";
                   flag = false;
                   break;
               }
           }
        }

        if(flag) {
            cout << "YES\n";
        }
    }
}




