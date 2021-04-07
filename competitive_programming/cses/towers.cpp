#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second

const ll inf = numeric_limits<ll>::max() / 4;

int main() {
    int n; cin >> n;
    vi v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    multiset<ll> st;
    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(v[i]);
        if(it != st.end()) {
            st.erase(it);
        }
        st.insert(v[i]);
    }
     
    cout << st.size()  << '\n';
}