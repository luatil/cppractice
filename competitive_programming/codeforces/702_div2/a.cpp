#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

auto is_power(int a) -> bool
{
    if( a == 1 ) return true;
    return (a&1) == 0 && is_power(a/2);
}

void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    REP(i, n) cin >> arr[i];

    int total = 0;
    int curr = 0;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int a = arr[i], b = arr[i+1];

        curr = (max(a, b)+min(a,b)-1) / min(a, b);

        if( curr > 2 )
        {
            total += log2(curr);
            if (is_power(curr)) total--;
        }
    }

    cout << total << '\n' ;
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
