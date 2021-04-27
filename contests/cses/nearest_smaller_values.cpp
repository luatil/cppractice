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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<pair<int, int>> stk;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while(!stk.empty() && stk.top().first >= v[i]) {
            stk.pop();
        }
        if(stk.empty()) {
            ans.push_back(0);
        } else {
            ans.push_back(stk.top().second);
        }
        stk.push({v[i], i+1});
    }

    for(const auto&el : ans) {
        cout << el << ' ';
    }
    cout << '\n';

}