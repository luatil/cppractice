#include <bits/stdc++.h> 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
 
const ll inf = numeric_limits<ll>::max() / 4;
 
bool prefix[300005];
 
void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
 
    memset(prefix, 0, sizeof(prefix));
 
    int count1 = 0;
    int inversion = 0;
    int last = 0;
    prefix[0] = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') {
            count1++;
        }
        if((i&1) == 1 && (i+1)/2 == count1) {
            prefix[i+1] = 1;
            inversion++;
            last = max(last, i+1);
        }
    }
 
    bool flag = true;
    if(inversion == 0) {
        flag = (a == b);
        cout << (flag ? "YES" : "NO") << '\n';
        return;
    }
 
    int curr = 0;
    int i;
    for(i = 0; i < last; i++) {
        if(prefix[i] == 1) {
            if (a[i] == b[i]) {
                curr = 0;
            } else {
                curr = 1;
            }
            i++;
        }
        if(a[i] == b[i] && curr == 1) {
            flag = false;
            break;
        }
        if(a[i] != b[i] && curr == 0) {
            flag = false;
            break;
        }
    }

    for(int j = last; j < n; j++) {
        if(a[j] != b[j]) {
            flag = false;
            break;
        }
    }
 
    cout << (flag ? "YES" : "NO") << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}