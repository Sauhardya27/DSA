#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int value){
	for (int i = 0; i < board.size(); i++){
		// Check for that row
		if (board[row][i] == value)
			return false;

		// Check for that col
		if (board[i][col] == value)
			return false;

		// Check for that 3*3 matrix
		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
			return false;
	}
	return true;
}

bool solve(vector<vector<int>> &board){
	int n = board[0].size();

	for (int row = 0; row < n; row++){
		for (int col = 0; col < n; col++){
			// Check for empty cell
			if (board[row][col] == 0){
				for (char val = 1; val <= 9; val++){
					if (isSafe(row, col, board, val)){
						board[row][col] = val;

						// Recursive call for other blank spaces
						bool solveNext = solve(board);
						if (solveNext)
							return true;
						else
							board[row][col] = 0;
					}
				}
				// If all the numbers got checked and none of them was a
				// possible solution
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<int>> &board) { solve(board); }