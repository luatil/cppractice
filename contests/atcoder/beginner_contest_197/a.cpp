#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    string s; cin >> s;
    rotate(s.begin(), s.begin() + 1, s.end());
    cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}