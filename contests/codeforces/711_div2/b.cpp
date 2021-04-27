#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const ll inf = numeric_limits<long long>::max() / 4;

void solve()
{
    ll n, w; cin >> n >> w;
    ll temp;
    multiset<ll> st;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        st.insert(temp);
    }

    ll height = 1;
    ll curr = w;
    while(!st.empty()) {
        auto it = st.upper_bound(curr);
        if(it != st.begin()) {
            it--;
            curr -= *it;
            st.erase(it);
        }
        else {
            curr = w;
            height++;
        }
    }

    cout << height << '\n';

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
