#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, unordered_map<int, int> &rowToCheck, unordered_map<int, int> &leftDiagonal, unordered_map<int, int> &rightDiagonal){
    if (rowToCheck.count(row) || leftDiagonal.count(row - col) || rightDiagonal.count(row + col)) {
        return false;
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

void solve(int col, vector<vector<int>> &board, unordered_map<int, int> &rowToCheck, unordered_map<int, int> &leftDiagonal, unordered_map<int, int> &rightDiagonal, vector<vector<int>> &ans, int n){
    //Base case
    if(col == n){
        addAnswer(board, ans, n);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, rowToCheck, leftDiagonal, rightDiagonal)){
			//Place the queen
            board[row][col] = 1;

			// Update occupied rows and diagonals
            rowToCheck[row] = 1;
            leftDiagonal[row - col] = 1;
            rightDiagonal[row + col] = 1;

			//Recursively solve for the next column
            solve(col+1, board, rowToCheck, leftDiagonal, rightDiagonal, ans, n);
            
			// Backtrack: remove the queen and update occupied rows and diagonals
            board[row][col] = 0;
            rowToCheck.erase(row);
            leftDiagonal.erase(row - col);
            rightDiagonal.erase(row + col);
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

	unordered_map<int, int> row, leftDiagonal, rightDiagonal;

    solve(0, board, row, leftDiagonal, rightDiagonal, ans, n);

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