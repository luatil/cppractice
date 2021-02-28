#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>

const int SIZE = 1e3+7;

auto string_to_bitmask(const string& s) -> int
{
    int total = 0;
    if(find(all(s), 'A') != s.end()) total+=4;
    if(find(all(s), 'B') != s.end()) total+=2;
    if(find(all(s), 'C') != s.end()) total+=1;
    return total;
}

vi dp(8);

void solve()
{
    int n; cin >> n;
    vector<pair<int, int> > v(n);

    string temp;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> temp;
        v[i].second = string_to_bitmask(temp);
    }

    for(int i = 1; i < 8; i++)
    {
        int min = 1e9;
        for(int j = 0; j < n; j++) 
        {
            if(v[j].second == i && v[j].first < min) min = v[j].first;
        }
        dp[i] = min;
    }

    dp[3] = min({dp[3], dp[1] + dp[2]});
    dp[5] = min({dp[5], dp[1] + dp[4]});
    dp[6] = min({dp[6], dp[2] + dp[4]});
    dp[7] = min({dp[7], dp[1] + dp[6], dp[3] + dp[4], dp[2] + dp[5], dp[6] + dp[5], dp[3] + dp[5], dp[3] + dp[6]});

    cout << (dp[7] == 1e9 ? -1 : dp[7]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
