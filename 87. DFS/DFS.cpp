//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void traversal(int node, vector<int> adjList[], vector<int> &visited, vector<int> &component){
        component.push_back(node);
        visited[node] = true;

        for(int i: adjList[node]){
            if(!visited[i])
                traversal(i, adjList, visited, component);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adjList[]) {
        vector<int> ans;
        vector<int> visited(V, 0);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                traversal(i, adjList, visited, ans);
            }
        }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}