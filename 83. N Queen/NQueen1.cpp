#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;

    //Check if any queen is present in the same row;
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }

    //Check if any queen is present in top-left diagonal
    x = row;
    y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x--;
    }

    //Check if any queen is present in bottom-left diagonal
    x = row;
    y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

void addAnswer(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    vector<int> temp;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            temp.push_back(board[i][j]);
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    //Base case
    if(col == n){
        addAnswer(board, ans, n);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, board, ans, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);

    return ans;
}

int main(){
	int n = 4;
	vector<vector<int>> result = solveNQueens(n);
	int row = result.size(), col = result[0].size();

	for (auto& row : result) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (row[i * n + j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }
	return 0;
}