#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

using vi = vector<ll>;
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

void solve(int index)
{
    ll n; cin >> n;
    n+=2;
    vi b(n);
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        tot += b[i];
    }

    sort(all(b));

    // The sum of all a's could only be on the last two positions. The problem if finding x.

    // First let's assume that sum(a) is on the last index
    for(ll i = 0; i < n-1; i++) {
        if(tot - b[i] == 2 * b.back()) {
            for(ll j = 0; j < n-1; j++) {
                if(j != i) cout << b[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }

    // Else x must be on the last index or it's not possible to form the sequence a

    if(tot - b.back() == 2 * b[n-2]) {
        for(ll i = 0; i < n-2; ++i) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }

    cout << "-1\n";
    return;
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
