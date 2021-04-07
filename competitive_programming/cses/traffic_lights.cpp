#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n; cin >> x >> n;
    set<int> st = {0, x};
    multiset<int> mst = {x};

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        auto it = st.lower_bound(a);
        auto lit = prev(it);

        mst.erase(mst.find(*it - *lit));
        mst.insert(a - *lit);
        mst.insert(*it - a);

        cout << *mst.rbegin() << ' ';
        st.insert(a);
    }
    cout << '\n';
    
}