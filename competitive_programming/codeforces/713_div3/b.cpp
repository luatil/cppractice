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

const int MAXN = 404;

void solve(int index)
{
    int n; cin >> n;
    vector<pi> v;
    vector<string> mat(n);
    for (ll i = 0; i < n; i++) {
        cin >> mat[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == '*') {
                v.push_back({i, j});
            }
        }
    }

    if(v[0].f == v[1].f) {
        // Same row
        mat[(v[0].f + 1) % n][v[0].s] = '*';
        mat[(v[1].f + 1) % n][v[1].s] = '*';
    } else if(v[0].s == v[1].s) {  
        // same column
        mat[v[0].f][(v[0].s + 1) % n] = '*';
        mat[v[1].f][(v[1].s + 1) % n] = '*';
    } else {
        // diagonal position
        mat[v[0].f][v[1].s] = '*';
        mat[v[1].f][v[0].s] = '*';
    }

    for(ll i = 0; i < n; i++) {
        cout << mat[i] << '\n';
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}