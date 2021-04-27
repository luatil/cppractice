#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>
const int inf = numeric_limits<int>::max();

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(auto&el : v) cin >> el;

    int res = inf;
    for(int mask = 0; mask < (1 << n) -1; mask++) {
            int ored = 0; 
            int xored = 0;
            for(int j = 0; j <= n; j++) {
                if((mask >> j & 1) || j == n) { // Kadane algorithm new set starting style.
                    xored ^= ored;
                    ored = v[j];
                }
                else {
                    ored |= v[j];
                }
            }
            res = min(res, xored);
            cout << mask << ' ' << xored << '\n';
        }
    cout << res << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}