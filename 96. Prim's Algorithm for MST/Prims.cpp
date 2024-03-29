#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector< vector<int> > &edges)
{
    unordered_map< int, list<pair<int,int>> > adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    //the parent array will keep track of the parent in formation of mst, mst array will keep track whether the vertices have been included in MST or not
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    //Starting the algorithm
    //Considering 1 as the starting node
    key[1] = 0;
    parent[1] = -1;

    //Traversing all the n-1 edges, here the indexing of the vertices start from 1, so the loop will start from 1
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;

        //Traversing all the n vertices, to fetch the min value
        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        //Traverse the adjacency list of u
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && key[v] > w){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    //Creating the result array, and inserting the vertices and the weights
    vector<pair<pair<int, int>, int>> result;
    //Here the loops start from 2, becoz the mapping of the nodes start from 1 and not from 0
    //Secondly we cannot start from 1, becoz 1 doesn't have a parent
    for(int i=2; i<=n; i++){
        int u = parent[i];
        int v = i;
        int w = key[i];
        result.push_back({{u,v},w});
    }
    return result;
}

int main(){
	vector<vector<int>> edges;
    int n, m, src;

    //cout << "Enter the number of nodes : ";
    cin >> n;
    
    //cout << "Enter the number of edges : ";
    cin >> m;

    //cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    vector< pair<pair<int,int>, int> >  answer = calculatePrimsMST(n, m, edges);

    for(pair<pair<int,int>, int> x : answer) {
        pair<int,int> a = x.first;
        int b = x.second;

        /*
            a.first -> u
            a.second -> v
            b -> weight
        */
        cout << a.first << "-" << a.second << " : " << b << endl;
    }

    return 0;
}
