#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long


void solve()
{
    int n, k1, k2; cin >> n >> k1 >> k2;
    int white_dominoes, black_dominoes; cin >> white_dominoes >> black_dominoes;

    int max_white = 0;
    int max_black = 0;
    if(k1 == k2)
    {
        max_white = k1;
        max_black = n - k1;
    }
    else 
    {
        max_white = min(k1, k2) +  ((max(k1, k2) - min(k1, k2))/2);
        max_black = min(n-k1, n-k2) +  ((max(n-k1, n-k2) - min(n-k1, n-k2))/2);
    }

    if(white_dominoes <= max_white && black_dominoes <= max_black)
    {
        cout << "YES\n";
        return;
    }
    else
    {
        cout << "NO\n";
        return;
    }
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
