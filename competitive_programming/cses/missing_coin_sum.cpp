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
    vi v(n); for(auto&el : v) cin >> el;
    sort(all(v));

    ll sum = 0;
    ll curr = 1;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        if(v[i] <= curr) {
            curr = sum +1;
        }
        else {
            break;
        }
    }
    cout << curr << '\n';

}