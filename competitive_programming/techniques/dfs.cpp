#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int number_of_vertices;
vector<vector<int> > graph;
vector<bool> visited;

void dfs(int i)
{
	if(!visited[i])
	{
		visited[i] = true;
		for_each(graph[i].cbegin(), graph[i].cend(), dfs);
	}
}

bool check_graph_connected_dfs()
{
	int start_vertex = 0;
	visited = vector<bool>(number_of_vertices, false);
	dfs(start_vertex);
	return all_of(visited.cbegin(), visited.cend(), true);
}