#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    string s; cin >> s;
    auto it = adjacent_find(s.begin(), s.end(), [](auto a, auto b){ return a == '1' && b == '1';});
    auto it2 = adjacent_find(it, s.end(), [](auto a, auto b){ return a == '0' && b == '0';});
    cout << (it2 < s.end() ? "NO" : "YES") << '\n';
}

void test()
{

}

void drive()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

int main()
{
    drive();
}
