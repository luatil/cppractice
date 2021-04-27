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

bool is_palindrome(const string& s1) {
    return equal(s1.begin(), s1.begin() + s1.size()/2, s1.rbegin());
}

void no() {
    cout << "-1\n";
}

void solve(int index)
{
    int a, b; cin >> a >> b;
    string str;
    cin >> str;

    int n = sz(str);

    for(ll i = 0; i < (n+1)/2; i++) {
        ll j = n - i - 1;
        if(str[i] == '?') {
            str[i] = str[j];
        } else if (str[j] == '?') {
            str[j] = str[i];
        } else if(str[i] != str[j]) {
            no();
            return;
        }
    }

    a -= count(all(str), '0');
    b -= count(all(str), '1');

    for(ll i = 0; i < (n+1)/2; i++) {
        ll j = n - i - 1;
        if(str[i] == '?') {
            if(a - 2 >= 0) {
                str[i] = '0';
                str[j] = '0';
                a -= 2;
            } else if(b - 2 >= 0) {
                str[i] = '1';
                str[j] = '1';
                b -= 2;
            }
        }
    }

    int pos = (n+1)/2-1;
    if(a == 1) {
        if(str[pos] == '1') {
            no();
            return;
        } else if(str[pos] == '?' || str[pos] == '0') {
            str[pos] = '0';
            a -= 1;
        } 
    }

    if(b == 1) {
        if(str[pos] == '0') {
            no();
            return;
        } else if(str[pos] == '?' || str[pos] == '1') {
            str[pos] = '1';
            b -= 1;
        } 
    }

    if(a == 0 && b == 0) {
        cout << str << '\n';
        return;
    } else {
        no();
        return;
    }


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