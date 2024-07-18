#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target){
	int row = matrix.size();
	int col = matrix[0].size();

	int s = 0, e = (row * col) - 1;

	while (s <= e){
		int mid = (s + e) / 2;
		int ele = matrix[mid / col][mid % col];

		if (ele == target)
			return 1;
		else if (ele < target)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return 0;
}

int main(){
	vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

	if(searchMatrix(arr, 22))
		cout << "Element found!" << endl;
	else
		cout << "Element not found!" << endl;
	return 0;
}