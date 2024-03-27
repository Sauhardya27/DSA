#include <bits/stdc++.h>
using namespace std;
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
	unordered_map<int, int> parent;
	parent[src] = -1;
	visited[src] = true;
	queue<int> Q;
	Q.push(src);

	while (!Q.empty())
	{
		int front = Q.front();
		Q.pop();

		for (auto neighbour : adj[front])
		{
			if (visited[neighbour] == true && parent[front] != neighbour)
				return true;
			else if (!visited[neighbour])
			{
				Q.push(neighbour);
				visited[neighbour] = true;
				parent[neighbour] = front;
			}
		}
	}
	return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
	visited[node] = true;

	for (auto neighbour : adj[node])
	{
		if (visited[neighbour] == true && parent != neighbour)
			return true;
		else if (!visited[neighbour])
		{
			bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
			if (cycleDetected)
				return true;
		}
	}
	return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
	unordered_map<int, list<int>> adj;
	for (int i = 0; i < m; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			// bool ans = isCyclicBFS(i, visited, adj);
			bool ans = isCyclicDFS(i, -1, visited, adj);
			if (ans)
				return "Yes";
		}
	}
	return "No";
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cout << "Enter no. of vertices and edges: ";
		cin >> n >> m;

		vector<vector<int>> edges(m, {0, 0});
		for (int i = 0; i < m; i++)
		{
			cin >> edges[i][0];
			cin >> edges[i][1];
		}

		cout << cycleDetection(edges, n, m) << endl;
	}

	return 0;
}
