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

ll digit_num(ll n) {
    ll ans = 0;
    while(n > 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

ll min_num(ll a, ll b) {

    if(a == b) {
        return a * 10;
    }

    vi va;
    ll na = a;
    while(na > 0) {
        va.push_back(na%10);
        na /= 10;
    }
    reverse(all(va));

    vi vb;
    ll nb = b;
    while(nb > 0) {
        vb.push_back(nb%10);
        nb /= 10;
    }
    reverse(all(vb));

    for(int i = 0; i < sz(vb); i++) {
        if(va[i] != vb[i]) {
            while(b < a) {
                b *= 10;
            }
            return b;
        }
    }

    if(va.back() == 9) {
        while(b < a) {
            b *= 10;
        }
        return b;
    }

    return a + 1;
}

void solve(int index)
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = 0;

    for(int i = 1; i < n; i++) {
        if(v[i] > v[i-1]) continue;

        ll nb = min_num(v[i-1], v[i]);
        ans += digit_num(nb) - digit_num(v[i]);
        v[i] = nb;
    }
    cout << "Case #" << index << ": " << ans << '\n';
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