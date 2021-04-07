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

vi prefix;

bool is_valid(const string&a, const string&b, int k) {
    if(k == prefix.size()-1) {
        return equal(a.begin()+prefix.back(), a.end(), b.begin()+prefix.back());
    }

    int st = prefix[k];
    int ed = prefix[k+1];
    
    bool flag = [&](){
        if(a[st] == b[st]) {
            return equal(a.begin()+st, a.begin()+ed, b.begin()+st);
        } else {
            return equal(a.begin()+st, a.begin()+ed, b.begin()+st, [](auto x, auto y){ return x != y;});
        }
    }();

    return flag && is_valid(a, b, k+1);
}

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    prefix.clear();

    int c1=0;
    prefix.push_back(0);
    for(int i=0; i<n; i++) {
        if(a[i] == '1') {
            c1++;
        }
        if((i%2)==1 && (i+1)/2==c1) {
            prefix.push_back(i+1);
        }
    }

    bool flag = is_valid(a, b, 0);

    cout << (flag ? "YES" : "NO") <<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}