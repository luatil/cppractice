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
// const int N = 10;
vector<int> adj[N];
bool visited[N];
int parent[N];
bool flag = false;
int ed, st;

void dfs(int i) {
    if(!visited[i] && !flag) {
        visited[i] = true;
        for(auto&el : adj[i]) {
            if(!visited[el]) {
                parent[el] = i;
                dfs(el);
            } else if(parent[i] != el) {
                // found the cycle
                flag = true;
                st = i;
                ed = el;
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


    for(int i = 1; i <= n && !flag; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    if(!flag) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        int curr = ed;
        while(curr != st) {
            ans.push_back(curr);
            curr = parent[curr];
        }
        ans.push_back(st);
        cout << ans.size() + 1 << '\n';
        cout << st << ' ';
        for(const auto&el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }

}