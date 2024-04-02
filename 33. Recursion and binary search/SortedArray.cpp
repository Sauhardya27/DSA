#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
	if(size == 0 || size == 1)
		return true;
	if(arr[0] > arr[1])
		return false;
	else
		return isSorted(arr+1, size-1);
}

int main(){
	int arr[] = {2, 4, 6, 1, 11, 17};
	if(isSorted(arr, 6))
		cout << "The given array is sorted" << endl;
	else
		cout << "The given array is not sorted" << endl;
	return 0;
}