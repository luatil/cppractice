#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long


int dp[100'007][2];

void solve()
{
    int n; cin >> n;
    REP(i, n) cin >> dp[i][0];
    REP(i, n) cin >> dp[i][1];

    if(n > 1)
    {
        dp[1][0] += dp[0][1];
        dp[1][1] += dp[0][0];
    }

    for(int i = 0; i < n-2; i++)
    {
        dp[i+2][0] += max(dp[i+1][1], dp[i][1] );
        dp[i+2][1] += max(dp[i+1][0], dp[i][0] );
    }

    cout << max(dp[n-1][0], dp[n-1][1]);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
