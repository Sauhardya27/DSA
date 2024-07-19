#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
	if(s > e)
		return false;
	
	int mid = (s+e)/2;
	if(arr[mid] == k)
		return true;
	else if(arr[mid] < k)
		return binarySearch(arr, mid+1, e, k);
	else
		return binarySearch(arr, s, mid-1, k);
}

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	if(binarySearch(arr, 0, 4, 7))
		cout << "Element found!" << endl;
	else 
		cout << "Element not found!" << endl;
	return 0;
}