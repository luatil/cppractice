#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int sum(int a, int b)
{
    const int answer = a + b;
    return (answer >= MOD ? answer - MOD : answer);
}


int main()
{
    int n, k, d; cin >> n >> k >> d;
    vector<vector<int> > dp(201, {0, 0});
    
    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
        // calculate how many you can make with all of them 
            dp[i+j][1] = sum(dp[i+j][1], dp[i][1]);
            if(j < d) 
            {
       // calculate how many you can do with lesser than d
                dp[i+j][0] = sum(dp[i+j][0], dp[i][0]);
            }
        }
    }
    
    dp[n][1] -= dp[n][0]; 

    cout << (dp[n][1] < 0 ? dp[n][1] + MOD : dp[n][1]) << '\n';
}
