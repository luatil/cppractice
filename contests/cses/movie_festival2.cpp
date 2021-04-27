#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<ll, ll> > a(n);
    for(int i =0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a), [](auto x, auto y) { return x.second < y.second;});

    ll ans = 1;
    multiset<int> st;
    for(int i = 0; i < k-1; ++i) st.insert(0);
    st.insert(a[0].second);
    for(int i = 1; i < n; i++) {
        auto it = st.upper_bound(a[i].first);
        if(it != st.begin()) {
            st.erase(prev(it));
            st.insert(a[i].second);
            ans++;
        }
    }

    cout << ans << '\n';
}