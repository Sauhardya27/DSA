#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums){
	int count = 0;
	int n = nums.size();
	for (int i = 1; i < n; i++){
		if (nums[i - 1] > nums[i])
			count++;
	}

	if (nums[n - 1] > nums[0])
		count++;

	return count < 2;
}

int main(){
	vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};
	int n = 8;

	if(check(arr))
		cout << "Given array is sorted and rotated" << endl;
	else
		cout << "Given array is not sorted and rotated" << endl;
	return 0;
}