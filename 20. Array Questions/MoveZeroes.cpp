#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums){
	int n = nums.size();
	int prev = 0, i = 0;

	while (i < n){
		if (nums[i] != 0){
			swap(nums[prev], nums[i]);
			prev++;
		}
		i++;
	}
}

int main(){
	vector<int> arr = {0, 1, 0, 5, 6, 0, 9, 3};
	int n = 8;

	cout << "Original array: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	moveZeroes(arr);

	cout << "Modified array: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}