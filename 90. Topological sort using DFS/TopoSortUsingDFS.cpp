#include <bits/stdc++.h>
using namespace std;
bool topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
	visited[node] = true;

	for (auto neighbour : adj[node])
	{
		if (!visited[neighbour])
			topoSort(neighbour, visited, s, adj);
	}

	s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
	unordered_map<int, list<int>> adj;
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	vector<bool> visited(v, 0);
	vector<int> ans;
	stack<int> s;

	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			topoSort(i, visited, s, adj);
	}

	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

int main()
{
	vector<vector<int>> edges;
	int n, m;

	int tc;
	cin >> tc;
	while (tc--)
	{
		cout << "Enter number of nodes and edges: ";
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
		}

		vector<int> topSort = topologicalSort(edges, n, m);

		cout << "Topological Sort : ";
		for (int x : topSort)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}