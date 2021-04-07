#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

const ll inf = numeric_limits<ll>::max() / 4;

int main() 
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto&el: v) cin >> el;

    ll maxi = v[0];
    ll curr = 0;
    for(int i = 0; i < n; i++) {
        if(curr + v[i] > v[i]) {
            curr += v[i];
        }
        else {
            curr = v[i];
        }
        maxi = max(curr, maxi);
    }

    cout << maxi << '\n';
}