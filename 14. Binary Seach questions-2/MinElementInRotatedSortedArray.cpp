#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums){
	int start = 0, end = nums.size() - 1, ans = nums[0];

	while (start <= end){
		int mid = start + (end - start) / 2;

		// Left side sorted array
		if (nums[mid] >= nums[0])
			start = mid + 1;

		// Right side sorted array
		else{
			ans = nums[mid];
			end = mid - 1;
		}
	}

	return ans;
}

int main(){
	vector<int> arr = {3, 8, 10, 17, 1};
	cout << "Minimum element in the given RSA: " << findMin(arr) << endl;
	return 0;
}