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

int table[34];

void solve(int index)
{
    // This feels like dp
    int n; cin >> n;
    int temp;
    vi v(n), p(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> temp; 
        v[i] = temp;
    }

    p[0] = v[0]; b[n-1] = v[n-1];
    for(int i = 1; i < n; i++) {
        p[i] = v[i] ^ p[i-1];
    }

    for(int i = n-2; i >= 0; i--) {
       b[i] = v[i] ^ b[i+1];
    }

    bool ans = false;
    for(int i = 0; i+1 < n; i++) {
        if(p[i] == b[i+1] || (p[i] == 0 && b[i] == 0) ) {
            ans = true; 
            break;
        }
    }

    cout << (ans ? "YES\n" : "NO\n");


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
