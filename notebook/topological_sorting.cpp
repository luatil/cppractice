#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(), v.end()

// Number of vertices
const int N = 6;
// vi adj[N];
int state[N];
vi topological_order;
// int processed[N];

vi adj[N] = {{1}, {2}, {5}, {0, 4}, {1, 2}, {}};

// Without cycle detection
void dfs(int i) {
    if(!state[i]) {
        state[i] = 1;
        for_each(adj[i].begin(), adj[i].end(), dfs);
    }
    if(state[i] != 2) {
        topological_order.push_back(i);
        state[i] = 2;
    }
}

int main() 
{
    memset(state, 0, sizeof(state));
    for(int i = 0; i < N; i++) dfs(i);
    reverse(all(topological_order));
    for(auto&el : topological_order) cout << el + 1<< ' ';
    cout << '\n';
}

