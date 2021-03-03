#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    int n, u, r, d, l; 
    vector<int> v(4);
    cin >> n >> v[0] >> v[1] >> v[2] >> v[3];

    if(all_of(all(v), [&](auto e){ return e <= n -2;}))
    {
        cout << "YES";
        return;
    }

    if(any_of(all(v), [&](auto e){ return e > n;}))
    {
        cout << "NO";
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        if(v[i] == n && v[(i+1)%4] == 0)
        {
            cout << "NO";
            return;
        }

        if(v[i] == n && v[(i-1)*(i>0) + (3*(i==0))] == 0) 
        {
            cout << "NO";
            return;
        }

        if(v[i] == n-1 && v[(i-1)*(i>0)+(3*(i==0))] == 0 && v[(i+1)%4] == 0) 
        {
            cout << "NO";
            return;
        }


    }
    cout << "YES";
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }
}
