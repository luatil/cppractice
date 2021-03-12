#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

void solve()
{
    bitset<1003> bt;
    int n, k;
    cin >> n >> k;
    if(k == 2)
    {
        cout << n-1 << '\n';
        cout << 1 << ' ';
        for(int i = 3; i <= n; i++)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    if(n == 1 && k == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if(n == 1)
    {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }
    bt[k] = 1;
    for(int i = 0; i * 2 < k; i++)
    {
        bt[i] = 1; 
    }
    cout << n - bt.count() + 1<< '\n';
    for(int i = 0; i <= n; i++)
    {
        if(!bt[i]) cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
