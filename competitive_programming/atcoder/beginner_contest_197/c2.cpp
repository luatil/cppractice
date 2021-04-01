#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>
const int inf = numeric_limits<int>::max() / 40;

int table[25][25];
int memo[25][25];


void solve()
{
    int n; cin >> n;
    vi v(n);
    for(auto&el : v) cin >> el;

    for(int i = 0; i < n; i++)
    {
        table[i][i] = v[i];
        for(int j = i+1; j < n; j++)
        {
            table[i][j] = v[j] | table[i][j-1];
        }
    }

    for(int offset = 0; offset < n; offset++)
    {
        for(int i = 0; i + offset < n; i++)
        {
            memo[i][i+offset] = [&]()
            {
                if(offset == 0) return v[i];
                if(offset == 1) return v[i] ^ v[i+offset];
                int mini = table[i][i+offset];
                for(int k = i; k + 1 <= i+offset; k++)
                {
                    mini = min({mini, memo[i][k] ^ memo[k+1][i+offset], table[i][k]^table[k+1][i+offset]});
                }
                return mini;
            }();
        }
    }

    cout << memo[0][n-1] << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}