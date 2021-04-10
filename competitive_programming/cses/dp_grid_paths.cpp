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

const int N = 1006;
char table[N][N];
int n; 
int memo[N][N];

ll dp(int i, int j) {
    if(table[i][j] == '*' || i >= n || i < 0 || j >= n || j < 0) {
        return 0;
    }
    if(i == 0 && j == 0) {
        return 1;
    }

    if(memo[i][j] != -1) {
        return memo[i][j];
    }

    memo[i][j] = (dp(i-1, j) + dp(i, j-1)) % MOD;

    return memo[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(n-1, n-1) << '\n';
}