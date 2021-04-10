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

int parent[N];
int rnk[N];

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int p, int q) {
    p = find_set(p);
    q = find_set(q);
    if(p != q) {
        if(rnk[p] < rnk[q]) swap(p, q);
        parent[q] = p;
        if(rnk[p] == rnk[q]) rnk[p]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) make_set(i);

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        union_sets(a, b);
    }

    int ans = 0;
    vector<pair<int, int>> vans;
    for(int i = 2; i <= n; i++) {
        if(find_set(i) != find_set(1)) {
            ans++;
            vans.push_back({1, i});
            union_sets(1, i);
        }
    }

    cout << ans << '\n';
    for(const auto&el : vans) {
        cout << el.f << ' ' << el.s << '\n';
    }

}