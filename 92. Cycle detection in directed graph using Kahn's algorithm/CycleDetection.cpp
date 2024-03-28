#include <bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u]. push_back(v);
    }

    //Using Kahn's Algorithm
    vector<int> indegree(n, 0);
    queue<int> q;
    int count = 0;

    for(auto i: adj){
        for(auto j: i.second)
            indegree[j]++;
    }

    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        count++;

        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(count == n)
      return false;
    else
      return true;
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