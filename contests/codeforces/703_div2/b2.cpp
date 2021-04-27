#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

int ans(int n0, int n1, int n2, int n)
{ 
    if(n0 == n1 && n2 == n1) return 0;

    if( n0 < n2 && n1 < n2 ) 
    {
        return (n-n0) + 2*(n-n1);
    }

    if( n1 < n0 && n2 < n0 ) 
    {
        return (n-n1) + 2*(n-n2);
    }

    if( n0 < n1 && n2 < n1 ) 
    {
        return (n-n2) + 2*(n-n0);
    }

    if( n0 < n1 && n1 == n2 )
    {
        return (n2 - n)*1 + (n1-n)*2;
    }

    if( n1 < n0 && n0 == n2 )
    {
        return (n0 - n)*1 + (n2-n)*2;
    }

    if( n2 < n1 && n1 == n0 )
    {
        return (n1 - n)*1 + (n0-n)*2;
    }

}
void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];

    int n0 = count_if(all(v), [](auto e) { return (e%3)==0; });
    int n1 = count_if(all(v), [](auto e) { return (e%3)==1; });
    int n2 = count_if(all(v), [](auto e) { return (e%3)==2; });

    cout << ans(n0, n1, n2, n/3) << '\n';

    
}


int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
