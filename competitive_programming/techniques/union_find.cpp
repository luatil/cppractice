#include <vector>
using namespace std;

// Weighted union find implementation

vector<int> parent;
vector<int> size;

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v)
{
    if(parent[v] = v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int p, int q)
{
    p = find_set(p);
    q = find_set(q);
    if(p != q)
    {
        if(size[p] > size[q]) swap(p, q);
        parent[p] = q;
        size[q] += size[p];
    }
}