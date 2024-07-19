#include <iostream>
using namespace std;

int findSum(int arr[], int size){
	if(size <= 0)
		return 0;

	return arr[size-1] + findSum(arr, size-1);
}

int main(){
	int arr[5] = {1, 2, 7, 4, 5};
	cout << "Sum of all the elements: " << findSum(arr, 5) << endl;
	return 0;
}