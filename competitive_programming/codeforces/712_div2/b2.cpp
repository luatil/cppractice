#include <bits/stdc++.h> 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
 
const ll inf = numeric_limits<ll>::max() / 4;

const int N = 300'005;
vector<int> prefix;
 
bool is_valid(const string& a, const string& b, int k) {
    if(k >= prefix.size()-1) {
        return equal(a.cbegin() + prefix.back(), a.cend(), b.cbegin() + prefix.back());
    }

    int st = prefix[k];
    int ed = prefix[k+1];
    bool flag = true;
    if(a[st] == b[st]) {
        flag = equal(a.begin() + st, a.begin() + ed, b.begin() + st);
    }

    if(a[st] != b[st]) {
        for(int i = st+1; i < ed; i++) {
            if(a[i] == b[i]) {
                flag = false;
                break;
            }
        }
    }
 
    if(flag) {
        return is_valid(a, b, k+1);
    }
 
    return false;
}
 
void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    int count1 = 0;
    int last = 0;
    prefix.clear();

    prefix.push_back(0);
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') {
            count1++;
        }
        if((i&1) == 1 && (i+1)/2 == count1) {
            prefix.push_back(i+1);
            last = max(last, i+1);
        }
    }
 
    bool flag = is_valid(a, b, 0);
 
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