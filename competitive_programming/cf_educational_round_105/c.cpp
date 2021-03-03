#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> v1, v2;
    vector<int> magic1, magic2;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp < 0) v2.push_back(-temp);
        else v1.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        if(temp < 0) magic2.push_back(-temp);
        else magic1.push_back(temp);
    }


}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
}
