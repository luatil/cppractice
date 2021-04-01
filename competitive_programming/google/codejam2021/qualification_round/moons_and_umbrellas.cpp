#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

int find_minimum_cost(const string& t, int x, int y) {
    int total = 0;
    // Filter and map
    string s;
    copy_if(t.cbegin(), t.cend(), back_inserter(s), [](auto e){return e != '?';});
    
    for(int i = 0; i + 1 < s.size(); i++) {
        if(s[i] == 'C' && s[i+1] == 'J') total += x;
        if(s[i] == 'J' && s[i+1] == 'C') total += y;
    }
    
    return total;
}

#define C 0
#define J 1
const int inf = numeric_limits<int>::max() / 40;
int memo[1005][2];

int find_minimum_cost_dp(const string& s, int x, int y) {
    memset(memo, inf, sizeof(memo));

    memo[0][C] = (s[0] == 'C' || s[0] == '?' ? 0 : inf);
    memo[0][J] = (s[0] == 'J' || s[0] == '?' ? 0 : inf);

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'C') {
            memo[i][C] = min(memo[i-1][C], memo[i-1][J] + y);
        }
        if(s[i] == 'J') {
            memo[i][J] = min(memo[i-1][C] + x, memo[i-1][J]);
        }
        if(s[i] == '?') {
            memo[i][J] = min(memo[i-1][C] + x, memo[i-1][J]);
            memo[i][C] = min(memo[i-1][C], memo[i-1][J] + y);
        }
    }

    return min(memo[s.size()-1][C], memo[s.size()-1][J]);
}

void solve(int index)
{
    int x, y; cin >> x >> y;
    string s; cin >> s;
    int ans = (x >= 0 && y >= 0 ? find_minimum_cost(s, x, y) : find_minimum_cost_dp(s, x, y));
    cout << "Case #" << index << ": " << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}
