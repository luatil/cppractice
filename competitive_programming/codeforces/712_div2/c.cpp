#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;

const ll inf = numeric_limits<ll>::max() / 4;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt = count(all(s), '1');
    if(s.front() == '0' || s.back() == '0' || (cnt & 1) == 1) {
        cout << "NO\n";
        return;
    }

    string a, b;
    int k = 0;
    bool flip = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        } else {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }

    cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}