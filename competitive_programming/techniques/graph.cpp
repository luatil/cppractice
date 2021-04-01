#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

int number_of_vertices;
std::vector< std::vector<int> > graph;
std::vector<char> visited;

void dfs(int i)
{
	if(!visited[i])
	{
		visited[i] = true;
		std::for_each(graph[i].cbegin(), graph[i].cend(), dfs);
	}
}

bool check_graph_connected_dfs()
{
	int start_vertex = 0;
	visited = std::vector<char>(number_of_vertices, false);
	dfs(start_vertex);
	return std::all_of(visited.cbegin(), visited.cend(), true);
}

bool check_graph_connected_bfs()
{
	int start_vertex = 0;
	std::vector<char> visited(number_of_vertices, false);
	std::queue<int> discovered;
	// those two next lines are always aggregated
	discovered.push(start_vertex);
	visited[start_vertex] = true;
	while(!discovered.empty())
	{
		int i = discovered.front();
		discovered.pop();
		for(const auto& el : graph[i])
		{
			if(!visited[el])
			{
	// those two next lines are always aggregated
				visited[el] = true;
				discovered.push(el);
			}
		}
	}
	return std::all_of(visited.cbegin(), visited.cend(), true);
}

// I really dislike this implementation
size_t vertex_num;
const int INF = std::numeric_limits<int>::max();
void dijkstra_via_priority_queue()
{
	std::vector< std::vector<std::pair<int, int> > > graph;
	std::vector<int> dist(vertex_num, INF);
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > discovered;
	int start_vertex = 0;
	dist[start_vertex] = 0;

	while(!discovered.empty())
	{
		std::pair<int, int> nearest = discovered.top();
		discovered.pop();

		int vertex = nearest.second, nearest_dist = nearest.first;
		
		if(nearest_dist <= dist[vertex])
		{
			for(const auto& el : graph[vertex])
			{
				int vertex2 = el.second, cost = el.first;
				if(dist[vertex2] > dist[vertex] + cost)
				{
					dist[vertex2] = dist[vertex] + cost;
					discovered.push(std::make_pair(dist[vertex2], vertex2));
				}
			}
		}

	}

}


int main()
{

}
