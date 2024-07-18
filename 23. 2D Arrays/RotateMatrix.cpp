#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix){
	// STEP 1: Transpose the matrix
	// STEP 2: Reverse each row
	int row = matrix.size();
	int col = matrix[0].size();

	for (int i = 0; i < row; i++){
		for (int j = i + 1; j < col; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col / 2; j++){
			swap(matrix[i][j], matrix[i][col - j - 1]);
		}
	}
	//For A.C.W. rotation:
	// for (int j = 0; j < col; j++) {
    // 	for (int i = 0; i < row/2; i++) {
    //   		swap(matrix[i][j], matrix[row - i -1][j]);
    // 	}
  	// }
}

int main(){
	vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	rotate(arr);

	cout << "Rotated matrix ->" << endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}