#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}

int findParent(vector<int> &parent, int node){
  if(parent[node] == node)
    return node;

  //Path compression
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v])
    parent[u] = v;
  else{
    parent[v] = u;
    rank[u]++;
  }
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0; i<n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
  vector<int> rank(n);

  makeSet(parent, rank, n);
  sort(edges.begin(), edges.end(), cmp);

  int minWt = 0;

  for(int i=0; i<edges.size(); i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int w = edges[i][2];

    if(u != v){
      minWt += w;
      unionSet(u, v, parent, rank);
    }
  }
  return minWt;
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

    int minWeight = minimumSpanningTree(edges, n);

    cout << "Weight of Kruskal's MST : " << minWeight << endl;

    return 0;
}