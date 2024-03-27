//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> Q;
        vector<int> ans;
        unordered_map<int, bool> visited;
        
        Q.push(0);
        visited[0] = 1;
        
        while(!Q.empty()){
            int frontNode = Q.front();
            Q.pop();
            
            ans.push_back(frontNode);
            
            for(int i: adj[frontNode]){
                if(!visited[i]){
                    Q.push(i);
                    visited[i] = 1;
                }
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}