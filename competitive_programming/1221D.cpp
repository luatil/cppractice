#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const long long inf = (long long) 1e18+6;


void solve()
{
    int n; cin >> n;
    vector< vector<ll> > dp(n, {0, 0, 0});
    vector<ll> arr(n);
    vector<ll> cost(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i] >> cost[i];

    dp[0][0] = 1;
    dp[0][1] = cost[0];
    dp[0][2] = 2*cost[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            long long minimum = inf;
            for(int k = 0; k <= 2; k++)
            {
                if((arr[i]+j)!=(arr[i-1] + k))
                {
                    minimum = min(minimum, dp[i-1][k]);
                }
            }
            dp[i][j] = j * cost[i] + minimum;
        }
    }

    std::cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << '\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
}
