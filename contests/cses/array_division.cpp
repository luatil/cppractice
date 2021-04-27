#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair


bool good(const vector<ll>& a, ll mid, int k) {
    int groups = 0;
    ll sum = 0;
    for(const auto&el : a) {
        if(el > mid) {
            return false;
        }
        if(sum + el > mid) {
            sum = 0;
            groups++;
        }
        sum += el;
    }
    if(sum > 0) {
        groups++;
    }
    return groups <= k;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, k; 
    cin >> n >> k;
    vector<ll> a;
    a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll lo = 0, hi = (ll) 1e18, ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (good(a, mid, k)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
}