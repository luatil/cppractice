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

const int N = 1e5+55;
const int M = 1e2+5;
int v[N], memo[M], old_memo[M];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if(v[0] == 0) {
        fill_n(old_memo, m+1, 1);
        fill_n(memo, m+1, 1);
        old_memo[0] = 0;
        memo[0] = 0;
    } else {
        memset(old_memo, 0, sizeof(int) * (m+1));
        memset(memo, 0, sizeof(int) * (m+1));
        old_memo[v[0]] = 1;
        memo[v[0]] = 1;
    }


    for(int i = 1; i < n; i++) {
        if(v[i] == 0) {
            for(int j = 1; j <= m; j++) {
                memo[j] = 0;
                for(int k = -1; k <= 1; k++) {
                    if(j + k >= 0 && j + k <= m) {
                        memo[j] = (memo[j] + old_memo[j+k]) % MOD;
                    }
                }
            }
        } else {
            memset(memo, 0, sizeof(int) * (m+1));
            int j = v[i];
            for(int k = -1; k <= 1; k++) {
                if(j + k >= 0 && j + k <= m) {
                    memo[j] = (memo[j] + old_memo[j+k]) % MOD;
                }
            }
        }
        copy(memo, memo + m + 1, old_memo);
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans + memo[i]) % MOD;
    }
    cout << ans << '\n';
}