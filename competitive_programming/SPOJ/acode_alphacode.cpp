#include <bits/stdc++.h>
using namespace std;

auto number_of_possible_decodings(string str) -> long long
{
    vector<int> dp(str.size());

    for(int i = str.size()-2; i >= 0; i--)
    {
        const int total = (str[i] - '0') * 10 + (str[i+1] - '0');
        if(total <= 26 && total != 10 && total != 20)
        {
            dp[i] = 1 + dp[i+1] + (i<str.size()-2)*dp[i+2];
        }
        else if(total > 26)
        {
            dp[i] = dp[i+1];
        }
    }

    return dp.front() + 1;
}

void solve()
{
    string s = "";
    while(true)
    {
        cin >> s;
        if(s == "0") break;
        cout << number_of_possible_decodings(s) << '\n';
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
