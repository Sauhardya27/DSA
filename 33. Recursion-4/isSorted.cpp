#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
	if(size == 0 || size == 1)
		return true;

	if(arr[0] > arr[1])
		return false;

	return isSorted(arr+1, size-1);
}

int main(){
	int arr[5] = {1, 2, 7, 4, 5};
	if(isSorted(arr, 5))
		cout << "The array is sorted" << endl;
	else
		cout << "The array is not sorted" << endl; 
	return 0;
}