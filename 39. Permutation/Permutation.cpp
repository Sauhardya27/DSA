#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans){
	if (index >= nums.size()){
		ans.push_back(nums);
		return;
	}

	for (int j = index; j < nums.size(); j++){
		swap(nums[index], nums[j]);
		solve(nums, index + 1, ans);
		swap(nums[index], nums[j]); // Backtracking
	}
}

vector<vector<int>> permute(vector<int> &nums){
	vector<vector<int>> ans;
	int index = 0;

	solve(nums, index, ans);

	return ans;
}

int main(){
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> result = permute(nums);

	int row = result.size();
	int col = result[0].size();

	cout << "[ ";
	for(int i=0; i<row; i++){
		cout << "[ ";
		for(int j=0; j<col; j++)
			cout << result[i][j] << " ";
		cout << "] ";
	}
	cout << "]";
	return 0;
}