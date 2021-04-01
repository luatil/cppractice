#include <vector>
#include <algorithm>
using namespace std;

// This is an implementation of kruskal with DSU or weighted union find

vector<int> parent;
vector<int> rnk; // rank

void make_set(int v) 
{
    parent[v] = v;
    rnk[v] = 0;
}

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

void kruskal()
{
    int n;
    vector<Edge> edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rnk.resize(n);


    for(int i = 0; i < n; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for(Edge e : edges) 
    {
        if(find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
}

void kruskal_2()
{
    int n;
    vector<Edge> edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rnk.resize(n);


    for(int i = 0; i < n; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for_each(edges.begin(), edges.end(), [&](auto e){
        if(find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    });
}

// With short circuit
void kruskal_3()
{    
    int n;
    int curr_edges = 0;
    vector<Edge> edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rnk.resize(n);


    for(int i = 0; i < n; i++) make_set(i);

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++)
    {
        Edge e = edges[i];
        if(curr_edges == n-1) break;
        if(find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
            curr_edges++;
        }
    }
}