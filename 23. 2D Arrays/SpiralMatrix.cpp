#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix){
	vector<int> ans;

	int row = matrix.size();
	int col = matrix[0].size();

	int count = 0;
	int totalElements = row * col;

	int startingRow = 0;
	int startingCol = 0;
	int endingRow = row - 1;
	int endingCol = col - 1;

	while (count < totalElements){
		// Adding starting row;
		for (int i = startingCol; count < totalElements && i <= endingCol; i++){
			ans.push_back(matrix[startingRow][i]);
			count++;
		}
		startingRow++;

		// Adding ending col;
		for (int i = startingRow; count < totalElements && i <= endingRow; i++){
			ans.push_back(matrix[i][endingCol]);
			count++;
		}
		endingCol--;

		// Adding ending row;
		for (int i = endingCol; count < totalElements && i >= startingCol; i--){
			ans.push_back(matrix[endingRow][i]);
			count++;
		}
		endingRow--;

		// Adding starting col;
		for (int i = endingRow; count < totalElements && i >= startingRow; i--){
			ans.push_back(matrix[i][startingCol]);
			count++;
		}
		startingCol++;
	}
	return ans;
}

int main(){
	vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> result = spiralOrder(arr);

	cout << "Spiral order matrix traversal -> ";
	for(int i=0; i<9; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}