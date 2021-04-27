#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const ll inf = numeric_limits<long long>::max() / 4;

void solve()
{
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    int i;

    int pos;
    int total = 2;
    for(pos = 0; pos < n; pos++)
    {
        if(s[pos] == '*') break;
    }

    int last;
    for(last = n-1; last >= 0; last--)
    {
        if(s[last] == '*') break;
    }

    if(pos == last)
    {
        cout << 1 << '\n';
        return ;
    }

    while(pos + k < last)
    {
        for(i = k; i >= 1; i--)
        {
            if(s[pos + i] == '*') break;
        }
        pos += i;
        total++;
    }

    cout << total << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
