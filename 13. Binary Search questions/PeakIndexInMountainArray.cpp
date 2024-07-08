#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr){
	int n = arr.size();
	int s = 0, e = n - 1;

	while (s < e)
	{
		int mid = (s + e) / 2;
		if (arr[mid] < arr[mid + 1])
			s = mid + 1;
		else
			e = mid;
	}
	return s;
}

int main(){
	vector<int>arr = {0, 10, 5, 2};
	cout << "Peak index in given array is: " << peakIndexInMountainArray(arr) << endl;
	return 0;
}