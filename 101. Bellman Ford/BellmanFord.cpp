#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int> dist(n, 1e8);
        dist[S] = 0;
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
                
            if(dist[u] != 1e8 && dist[u] + w < dist[v])
                return vector<int> (1, -1);
        }
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}