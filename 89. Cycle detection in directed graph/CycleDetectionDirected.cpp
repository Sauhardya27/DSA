#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

bool isCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected = isCycleDFS(neighbour, visited, dfsVisited, adj);
      if(cycleDetected)
        return true;
    }
    else if(dfsVisited[neighbour])
      return true;
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adj;

  //Create adjacency list
  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  //Check for all the vertices and disconnected components
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      bool ans = isCycleDFS(i, visited, dfsVisited, adj);
      if(ans)
        return 1;
    }
  }
  return 0;
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

		vector<pair < int, int > > edges(m, {0, 0});
		for (int i = 0; i < m; i++)
		{
			int u, v;
        	cin >> u >> v;
        	edges.push_back({u,v});
		}

		if(detectCycleInDirectedGraph(n, edges))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}

//Optimized code
/*
bool isCyclicDFS(int node, vector<int> &nodeStates, vector<int> adj[]) {
        nodeStates[node] = 1; // Mark as Visiting

        for (auto neighbour : adj[node]) {
            if (nodeStates[neighbour] == 1) {  // Cycle detected (back edge)
                return true;
            } else if (nodeStates[neighbour] == 0) {
                bool cycleDetected = isCyclicDFS(neighbour, nodeStates, adj);
                if (cycleDetected) {
                    return true;
                }
            }
        }

        nodeStates[node] = 2; // Mark as Visited
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> nodeStates(V, 0); // Initialize all nodes to Unvisited (0)

        for (int i = 0; i < V; ++i) {
            if (nodeStates[i] == 0) { // Explore unvisited nodes
                if (isCyclicDFS(i, nodeStates, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
*/