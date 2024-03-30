#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &visited, vector<vector<int>> &result, unordered_map<int, list<int>> &adj){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr: adj[node]){
        if(nbr == parent)
            continue;
        else if(!visited[nbr]){
            dfs(nbr, node, timer, disc, low, visited, result, adj);
            low[node] = min(low[node], low[nbr]);

            //Check for bridge
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int>disc(v, -1);
    vector<int>low(v, -1);
    int parent = -1;
    unordered_map<int, bool>visited;

    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!visited[i])
            dfs(i, parent, timer, disc, low, visited, result, adj);
    }

    return result;
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

    vector<vector<int>> answer = findBridges(edges, n, m);

    //cout << "Bridge Edges : ";
    for(int i=0; i<answer.size(); i++) {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "] ";
    }
	if(answer.empty())
		cout << "0" << endl;
	else	
		cout << endl;
	
    return 0;
}