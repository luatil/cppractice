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

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    a.pb('0'); b.pb('0');
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (a[i] == '1') - (a[i] == '0');
        if((a[i] == b[i]) != (a[i+1] == b[i+1]) && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}