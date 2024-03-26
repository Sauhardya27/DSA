#include <bits/stdc++.h>
using namespace std;


class Graph{
	public:
	vector <vector<int>> adjMat;

	Graph(int nodeCount){
		adjMat = vector<vector<int>> (nodeCount, vector<int> (nodeCount, 0));
	}

	void addEdge(int u, int v, bool direction){
		//direction = false -> Undirected graph
		//direction = true -> Directed graph

		//Adding edge between u and v
		adjMat[u][v] = 1;

		if(direction == false)
			adjMat[v][u] = 1;
	}

	void print(){
		int n = adjMat.size();
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				cout << adjMat[i][j] << " ";

			cout << endl;
		}
	}
};

int main(){
	Graph G(5);

	G.addEdge(0, 1, 0);
	G.addEdge(0, 4, 0);
	G.addEdge(1, 2, 0);
	G.addEdge(1, 3, 0);
	G.addEdge(2, 3, 0);
	G.addEdge(3, 4, 0);

	cout << "Adjacency Matrix: " << endl;
	G.print();
	return 0;
}