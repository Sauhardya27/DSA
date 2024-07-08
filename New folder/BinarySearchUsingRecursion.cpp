#include <iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key){
	if(n < 1)
		return false;
	
	int mid = (n-1)/2;
	if(arr[mid] == key)
		return true;
	else if(key > arr[mid])
		return binarySearch(arr+mid+1, n-mid-1, key);
	else	
		return binarySearch(arr, n-mid-1, key);
}

int main(){
	int arr[] = {2, 4, 6, 11, 17, 54};
	if(binarySearch(arr, 6, 69))
		cout << "Element found" << endl;
	else
		cout << "Element is not present in the array" << endl;

	return 0;
}