#include <bits/stdc++.h>
using namespace std;

/*int min(int a, int b){
	if(a < b)
		return a;
	return b;
}*/

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &ap){
	visited[node] = true;
	disc[node] = low[node] = timer++;
	int child = 0;

	for(auto nbr: adj[node]){
		if(nbr == parent)
			continue;
		else if(!visited[nbr]){
			dfs(nbr, node, timer, disc, low, visited, adj, ap);
			low[node] = min(low[node], low[nbr]);
			//Check for ap
			if(low[nbr] >= disc[node] && parent != -1)
				ap[node] = 1;

			child++;
		}
		else{
			low[node] = min(low[node], disc[nbr]);
		}
	}
	if(parent == -1 && child > 1)
		ap[node] = 1;
}

vector<int> articulationPoint(vector<pair<int, int>> &edges, int n){
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int timer = 0;
	int parent = -1;
	
	vector<int> disc(n, -1);
	vector<int> low(n, -1);
	vector<bool> visited(n, false);
	vector<int> ap(n, 0);

	for(int i=0; i<n; i++){
		if(!visited[i])
			dfs(i, parent, timer, disc, low, visited, adj, ap);
	}
	return ap;
}

int main(){
	int n = 5;
	vector<pair<int, int>> edges;
	/*edges.push_back(make_pair(0, 1));
	edges.push_back(make_pair(0, 4));
	edges.push_back(make_pair(1, 4));
	edges.push_back(make_pair(2, 4));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(3, 4));*/

	/*edges.push_back(make_pair(0, 1));
	edges.push_back(make_pair(0, 5));
	edges.push_back(make_pair(1, 5));
	edges.push_back(make_pair(2, 5));
	edges.push_back(make_pair(4, 5));
	edges.push_back(make_pair(3, 4));
	edges.push_back(make_pair(2, 3));*/

	edges.push_back(make_pair(0, 1));
	edges.push_back(make_pair(1, 2));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(3, 4));

	vector<int> artPnt = articulationPoint(edges, n);

	cout << "Articulation nodes are: ";
	for(int i=0; i<n; i++){
		if(artPnt[i] != 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}