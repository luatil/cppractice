#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const ll inf = numeric_limits<ll>::max() / 4;

int main() 
{
    int n; cin >> n;
    vector<pi> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].f;
        v[i].s = i;
    }
    sort(all(v));
    ll ans = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].s < v[i-1].s) {
            ans++;
        }
    }
    cout << ans << '\n';
}