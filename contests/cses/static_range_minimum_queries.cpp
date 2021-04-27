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

const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;

const int MAXN = 2 * 1e5 + 55;
int n, q;
const int K = 25;
int a[MAXN];
int st[MAXN][K];
int lg[MAXN+1];

// Sparse table solution
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    lg[1] = 0; 
    for(int i = 2; i <= MAXN; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    int L, R;
    while(q--) {
        cin >> L >> R;
        L--;
        R--;
        int j = lg[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        cout << minimum << '\n';
    }
}