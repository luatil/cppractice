#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

vector<int> adj[(int)2e5+7];

void solve()
{
    int number_of_vertices; cin >> number_of_vertices;
    int temp1, temp2;
    for(int i = 1; i < number_of_vertices; i++)
    {
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }

    bool is_fib[(int)2e5+7];
    int a = 1, b = 1, temp;
    is_fib[1] = true;
    for(int i = 0; i < 2e5+7; i++)
    {
        temp = b;
        b = a + b;
        a = temp;
        is_fib[temp] = true;
    }

    if(!is_fib[number_of_vertices])
    {
        cout << "NO\n"
        return;
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
