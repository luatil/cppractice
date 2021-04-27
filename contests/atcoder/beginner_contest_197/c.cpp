#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>
const int inf = numeric_limits<int>::max() / 40;

int table[25][25];
int memo[25][25];

int dp(vi v, int i, int j)
{
    if(i > j) return inf;
    if(memo[i][j] != -1) return memo[i][j];

    if(i == j) return memo[i][j] = v[i];
    int mini = table[i][j];
    for(int k = i; k + 1 <= j; k++)
    {
        mini = min({mini, dp(v, i, k) ^ dp(v, k+1, j), table[i][k] ^ table[k+1][j]});
    }
    memo[i][j] = mini;
    return mini;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(auto&el : v) cin >> el;
    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < n; i++)
    {
        table[i][i] = v[i];
        for(int j = i+1; j < n; j++)
        {
            table[i][j] = v[j] | table[i][j-1];
        }
    }

    cout << dp(v, 0, n-1) << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}