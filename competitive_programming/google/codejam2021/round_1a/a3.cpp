#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mkp make_pair

const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;

string plus_one(string str) {
    int carry = 0;
    for(int i = str.length() - 1; i >= 0; i++) {
        if(str[i] - '0' < 9) {
            str[i] += 1;
            return str;
        } else {
            str[i] = '0';
        }
    }
}

void solve(int index)
{
    ll ans = 0;
    ll n; cin >> n;
    vector<string> v;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++) {
        if(v[i].length() > v[i-1].length()) {
            continue;
        } else if(v[i].length() == v[i-1].length()) {
            if(v[i-1] >= v[i]) {
                v[i].push_back('0');
                ans++;
            }
        } else if(v[i].length() < v[i-1].length()) {
            // First try appending zeros, then try appending nines. 
            // Else return a + 1
            string zero_append = v[i];
            while(zero_append.length() < v[i-1].length()) {
                zero_append.push_back('0');
            }

            if(zero_append > v[i-1]) {
                ans += zero_append.length() - v[i].length();
                v[i] = zero_append;
                continue;
            }

            string nine_append = v[i];
            while(nine_append.length() < v[i-1].length()) {
                nine_append.push_back('9');
            }

            if(v[i-1] >= nine_append) {
                zero_append.push_back('0');
                ans += zero_append.length() - v[i].length();
                v[i] = zero_append;
                continue;
            }

            ans += v[i-1].length() - v[i].length();
            v[i] = plus_one(v[i-1]);
        }
    }
    cout << "Case #" << index << ": " << ans << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}