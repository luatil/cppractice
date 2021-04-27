#include <bits/stdc++.h> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;

ordered_set<int> v;

void rec(int start, int k) {
    if(v.size() == 1) {
        cout << *v.find_by_order(0) << '\n';
        return;
    }
    int pos = (start+k)%v.size();
    int ans = *v.find_by_order(pos);
    cout << ans << ' ';
    v.erase(ans);
    rec(pos, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        v.insert(i);
    }
    rec(0, k);
}
