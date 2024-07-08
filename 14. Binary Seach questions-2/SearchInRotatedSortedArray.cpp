#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int s, int n, int k){
	int e = n - 1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (arr[mid] == k)
			return mid;
		else if (arr[mid] > k)
			e = mid - 1;
		else
			s = mid + 1;
	}
	return -1;
}

int getPivot(vector<int> &arr, int n){
	int s = 0, e = arr.size() - 1;

	while (s < e){
		int mid = (s + e) / 2;
		if (arr[mid] >= arr[0])
			s = mid + 1;
		else
			e = mid;
	}
	return s;
}

int search(vector<int> &nums, int target){
	int n = nums.size();
	int pivot = getPivot(nums, n);

	if (target >= nums[pivot] && target <= nums[n - 1])
		return binarySearch(nums, pivot, n, target);
	else
		return binarySearch(nums, 0, pivot, target);
}

int main(){
	vector<int> arr = {3, 8, 10, 17, 1};
	if(search(arr, 3) >= 0)
		cout << "Element found" << endl;
	else
		cout << "Element not found" << endl;
	return 0;
}