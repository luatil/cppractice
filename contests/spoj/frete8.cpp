#include <bits/stdc++.h>
using namespace std;
vector<int> parent(1200);
vector<int> rnk(1200); // rank

void make_set(int v) 
{
    parent[v] = v;
    rnk[v] = 0;
}
// 
// find_leader may be a better name
int find_set(int v)
{
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
       if(rnk[a] < rnk[b]) swap(a, b);
       parent[b] = a;
       if(rnk[a] == rnk[b]) rnk[a]++;
    }
}

struct Edge 
{
    int u, v, weight;
    bool operator < (Edge const& other) {
        return weight < other.weight;
    }
};

int N, M;

void solve()
{
    vector<Edge> edges;
    int x, y, z;
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
        edges.push_back({y, x, z});
    }

    int cost = 0;
    vector<Edge> result;

    for(int i = 0; i < N; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for(auto e : edges)
    {        
        if(find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << cost << '\n';
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    solve();
    return 0;
}
