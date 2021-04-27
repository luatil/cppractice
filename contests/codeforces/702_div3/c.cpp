#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

void solve()
{
    ll x; cin >> x;

    ll left = 1;
    ll right = 10'004;

    while(left <= right)
    {
        ll total = (right*right*right) + (left*left*left);
        if(total == x) 
        {
            cout << "YES\n";
            return;
        }

        if(total < x) 
        {
            left++;
        }

        if(total > x) 
        {
            right--;
        }
    }

    cout << "NO\n";
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
