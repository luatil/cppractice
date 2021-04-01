#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>

template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}


void solve()
{
    int n, m, k, f;
    cin >> n >> m;
    vector<int>table(n+1);
    vector<vector<int> > adj(m, vector<int>(0));
    for(int i = 0; i < m; i++)
    {
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> f;
            adj[i].push_back(f);
        }
    }

    vi result;

    for(int i = 0; i < m; i++)
    {
        result.push_back(adj[i].front());
        table[adj[i].front()]++;
    }

    auto it = find_if(all(result), [&](auto e){ return table[e] > (m+2-1)/2;});

    if(it != result.end())
    {
        f = *it;
        for(int i = 0; i < m; i++)
        {
            if(result[i] == f && adj[i].size() > 1 && table[f] > (m+2-1)/2)
            {
                result[i] = adj[i].back();
                table[f]--;
            }
        }
    }

    if(it != result.end() && table[f] > (m+2-1)/2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    output_vector(result);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
