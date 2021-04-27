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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    multiset<int> st = {1, 2, 2,3, 3, 4};
    for(const auto&el : st) {
        cout << el << ' ';
    }
    cout << '\n';
    st.erase(2);
    for(const auto&el : st) {
        cout << el << ' ';
    }
    cout << '\n';
    st.erase(st.find(3));
    for(const auto&el : st) {
        cout << el << ' ';
    }
    cout << '\n';
}