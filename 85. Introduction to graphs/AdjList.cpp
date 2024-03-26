#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph{
	public:
	map<T, list<T>>m;

	void addEdge(T u, T v, bool direction){
		m[u].push_back(v);

		if(direction == false)
			m[v].push_back(u);
	}

	void print(){
		for(auto i : m){
			cout << i.first << " -> ";
			for(auto j:i.second)
				cout << j << " ";

			cout << endl;
		}
	}
};

int main(){
	Graph<int> G;

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