#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
	vector<int> result;
	for (int col = 0; col < mCols; col++){
		if (col & 1){
			// For odd cols
			for (int row = nRows - 1; row >= 0; row--)
				result.push_back(arr[row][col]);
		}
		else{
			for (int row = 0; row < nRows; row++)
				result.push_back(arr[row][col]);
		}
	}
	return result;
}

int main(){
	vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<int> result = wavePrint(arr, 3, 4);

	cout << "Wave like print -> ";
	for(int i=0; i<12; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}