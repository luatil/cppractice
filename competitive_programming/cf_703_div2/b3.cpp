#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e2 + 7;


int dp[SIZE][SIZE][SIZE];

int ans(int n0, int n1, int n2)
{ 
    if(n0 == n1 && n1 == n2) return 0;

    if(n0 < 0 || n1 < 0 || n2 < 0) return SIZE;

    if (dp[n0][n1][n2] == 0) {
        dp[n0][n1][n2] = 1 + min(ans(n0-1, n1+1, n2),
                                 min(ans(n0, n1-1, n2+1), 
                                 ans(n0+1, n1, n2-1)));
    }

    return dp[n0][n1][n2];

}
void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];

    int n0 = count_if(all(v), [](auto e) { return (e%3)==0; });
    int n1 = count_if(all(v), [](auto e) { return (e%3)==1; });
    int n2 = count_if(all(v), [](auto e) { return (e%3)==2; });

    cout << ans(n0, n1, n2) << '\n';

    
}


int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
