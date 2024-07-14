#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);
    for(int i=0; i<n; i++){
        temp[(i+k)%n] = nums[i]; //To rotate to left: (i+n-k)%n
    }

    nums = temp;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = 8;

	cout << "Original array: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;

	rotate(arr, 3);

	cout << "Modified array: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}