#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    ll n, x; cin >> n >> x;
    multiset<ll> st;
    ll temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        st.insert(temp);
    }

    ll curr = x; 
    ll ans = 1;
    ll g = 0;
    while(!st.empty()) {
        auto it = st.upper_bound(curr);
        if(it == st.begin() || g == 2) {
            ans++;
            curr = x;
            g = 0;
        }
        else {
            it--;
            curr -= *it;
            st.erase(it);
            g++;
        }
    }

    cout << ans << '\n';

}