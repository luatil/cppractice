#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

const ll inf = numeric_limits<ll>::max() / 4;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        ll temp; cin >> temp;
        prefix[i] = prefix[i-1] + temp;
    }

    ll ans = -inf;
    ll curr = 0;
    multiset<ll> st;
    for(int i = a; i <= n; i++) {
        if(i > b)
            st.erase(st.find(prefix[i-b-1]));
        st.insert(prefix[i-a]);
        curr = prefix[i] - *st.begin();
        ans = max(ans, curr);
    }

    cout << ans << '\n';
}