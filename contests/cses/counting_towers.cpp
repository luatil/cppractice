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

const int N = 1e6+44;
ll memo[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    vector<int> queries;
    int x = t;
    while(x--) {
        int n; cin >> n;
        queries.push_back(n);
    }

    int high = *max_element(all(queries));

    memo[1][0] = 1;
    memo[1][1] = 1;

    for(int i = 2; i <= high; i++) {
        memo[i][0] = (2 * memo[i-1][0] + memo[i-1][1]) % MOD;
        memo[i][1] = (memo[i-1][0] + 4 * memo[i-1][1]) % MOD;
    }

    for(int i = 0; i < t; i++) {
        cout << (memo[queries[i]][0] + memo[queries[i]][1]) % MOD << '\n';
    }
}