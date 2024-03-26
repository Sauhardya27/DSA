#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
	vector<vector<int>> arr(n);

	for (int i = 0; i < n; i++)
		arr[i].push_back(i);

	for (int i = 0; i < m; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	return arr;
}

int main()
{
	int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    vector< vector<int> > edges(m, {0,0});

	//Take edges input by entering the two vertices between which edge exists
    for(int i=0; i<m; i++) {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector< vector<int> > solution = printAdjacency(n, m, edges);

    for(auto i : solution) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
	
	return 0;
}