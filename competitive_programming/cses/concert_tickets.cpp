#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    ll n, m; cin >> n >> m;
    vector<ll> t(m);
    multiset<ll> st;
    ll temp;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        st.insert(temp);
    }
    for(int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    for(int i = 0; i < m; ++i) {
        auto it = st.upper_bound(t[i]);
        if(it == st.begin()) {
            cout << -1 << '\n';
        }
        else {
            it--;
            cout << *it << '\n';
            st.erase(it);
        }
    }

}