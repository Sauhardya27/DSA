#include <bits/stdc++.h> 
using namespace std;

bool isSafe(vector<vector<int>>& arr, int n, int x, int y, vector<vector<int>>& visited){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
        return true;
    else
        return false;
}

void solve(vector < vector < int >> & arr, int n, int x, int y, vector<string>& ans, vector<vector<int>> &visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //Down
    if(isSafe(arr, n, x+1, y, visited)){
        path.push_back('D');
        solve(arr, n, x+1, y, ans, visited, path);
        path.pop_back();
    }

    //Left
    if(isSafe(arr, n, x, y-1, visited)){
        path.push_back('L');
        solve(arr, n, x, y-1, ans, visited, path);
        path.pop_back();
    }

    //Right
    if(isSafe(arr, n, x, y+1, visited)){
        path.push_back('R');
        solve(arr, n, x, y+1, ans, visited, path);
        path.pop_back();
    }

    //Up
    if(isSafe(arr, n, x-1, y, visited)){
        path.push_back('U');
        solve(arr, n, x-1, y, ans, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    //considering vertical axis as x and horizontal one as y
    vector<string> ans;
    if(arr[0][0] == 0)
        return ans;

    int srcx = 0, srcy = 0;
    vector<vector<int>> visited = arr;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
    }

    string path = "";
    solve(arr, n, srcx, srcy, ans, visited, path);
    sort(ans.begin(), ans.end());

    return ans;
}