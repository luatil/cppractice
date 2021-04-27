#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    oset<pair<int, int>> st;
    for(int i = 0; i < k-1; i++) {
        st.insert({v[i], i});
    }
    for(int i = k-1; i < n; i++) {
        st.insert({v[i], i});
        auto ans = [&]() {
            if((k&1)==1) {
                return (*st.find_by_order(k/2)).f;
            } 
            return min((*st.find_by_order(k/2)).f, (*st.find_by_order(k/2-1)).f);
        }();
        cout << ans << ' ';
        st.erase({v[i-k+1], i-k+1});
    }
    cout << '\n';
}