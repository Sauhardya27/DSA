#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
	// Create adjacency list
	unordered_map<int, list<pair<int, int>>> adj;
	for (int i = 0; i < edges; i++)
	{
		int u = vec[i][0];
		int v = vec[i][1];
		int w = vec[i][2];

		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// Create distance array and set
	vector<int> dist(vertices, INT_MAX);
	set<pair<int, int>> st;

	// Initialize values for source node is distance array and push into set
	dist[source] = 0;
	st.insert(make_pair(0, source));

	while (!st.empty())
	{
		// Fetch top element
		auto top = *(st.begin());

		// Fetching the distance and value of the top node
		int nodeDistance = top.first;
		int topNode = top.second;

		// remove top node
		st.erase(st.begin());

		// Traverse all the neighbours
		for (auto neighbours : adj[topNode])
		{
			if (nodeDistance + neighbours.second < dist[neighbours.first])
			{
				// Search if the current neighbour exists in the set, if yes then erase it
				auto record = st.find(make_pair(dist[neighbours.first], neighbours.first));
				if (record != st.end())
					st.erase(record);

				// Update the distance
				dist[neighbours.first] = nodeDistance + neighbours.second;

				// Push the updated distance in the set
				st.insert(make_pair(dist[neighbours.first], neighbours.first));
			}
		}
	}
	return dist;
}

int main()
{
	vector<vector<int>> edges;
	int n, m, src;

	int tc;
	cin >> tc;
	while (tc--)
	{
		// cout << "Enter the number of nodes : ";
		cin >> n;

		// cout << "Enter the number of edges : ";
		cin >> m;

		// cout << "Enter the edges : " << endl;
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edges.push_back({u, v, w});
		}

		cout << "Enter the source : ";
		cin >> src;

		vector<int> answer = dijkstra(edges, n, m, src);
		cout << "The shortest path : ";
		for (int x : answer)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
