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

const int N = 1003, M = 1003;
int n, m;
char mapi[N][M];
bool visited[N][M];

int px[] = {1, 0, -1, 0};
int py[] = {0, -1, 0, 1};

void dfs(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || mapi[i][j] == '#') return;

    if(!visited[i][j]) {
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            dfs(i+py[k], j+px[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mapi[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mapi[i][j] != '#' && !visited[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';
}