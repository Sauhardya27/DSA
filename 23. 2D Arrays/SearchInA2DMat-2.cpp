#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    //Start from the top right corner
    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0){
        int ele = matrix[rowIndex][colIndex];

        if(ele == target)
            return 1;
        else if(ele < target)
            rowIndex++;
        else
            colIndex--;
    }
    return 0;
}

int main(){
	vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

	if(searchMatrix(arr, 0))
		cout << "Element found!" << endl;
	else
		cout << "Element not found!" << endl;
	return 0;
}