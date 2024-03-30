#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj){
	visited[node] = true;

	for(auto nbr: adj[node]){
		if(!visited[nbr])
			topoSort(nbr, visited, st, adj);
	}

	st.push(node);
}

void revDFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose){
	visited[node] = true;

	for(auto nbr: transpose[node]){
		if(!visited[nbr])
			revDFS(nbr, visited, transpose);
	}
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	stack<int> st;
	vector<bool> visited(n, false);

	//Topologically sort the nodes of the graph
	for(int i=0; i<n; i++){
		if(!visited[i])
			topoSort(i, visited, st, adj);
	}

	//Transpose the graph
	unordered_map<int, list<int>> transpose;
	for(int i=0; i<n; i++){
		visited[i] = false;
		for(auto nbr: adj[i])
			transpose[nbr].push_back(i);
	}

	//DFS call on topological sort
	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();

		if(!visited[top]){
			count++;
			revDFS(top, visited, transpose);
		}
	}	
	return count;
}

int main(){
	vector<vector<int>> edges;
    int n, m;

    //cout << "Enter the value of n : ";
    cin >> n;

    //cout << "Enter the value of m : ";
    cin >> m;

    //cout << "Enter the edges :" << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    int answer = stronglyConnectedComponents(n, edges);

    cout << "Total Strongly Connected Components : " << answer << endl;

    return 0;
}