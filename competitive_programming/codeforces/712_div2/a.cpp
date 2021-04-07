#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define mp make_pair

const ll inf = numeric_limits<ll>::max() / 4;

bool is_palindrome(const string& s) {
    return equal(s.cbegin(), s.cbegin() + s.size()/2, s.rbegin());
}

void solve() {
    string s; cin >> s;
    if(!is_palindrome(s + 'a')) {
        cout << "YES\n" << s << 'a' << '\n';
    } else if(!is_palindrome('a' + s)) {
        cout << "YES\n" << 'a' << s << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}