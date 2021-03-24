#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    int N; cin >> N;
    vector<int> mex(N);
    vector<int> mex2;
    for(auto&el : mex) cin >> el;

    sort(all(mex));

    for(int i = 1; i < N; i++)
    {
        if(mex[i] == mex[i-1]) mex2.push_back(mex[i]);
    }

    auto last = unique(all(mex));
    mex.erase(last, mex.end());

    for(const auto&el : mex) cout << el << ' ';
    for(const auto&el : mex2) cout << el << ' ';
    cout << '\n';
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
    //test();
    drive();
}
