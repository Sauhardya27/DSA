#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n){
	if(n == 0 || n == 1)
		return;

	for(int i=0; i<n-1; i++){
		if(arr[i] > arr[i+1])
			swap(arr[i], arr[i+1]);
	}

	return bubbleSort(arr, n-1);
}

int main(){
	int arr[] = {3, 5, 1, 17, 9, 6, 2, 7};
	
	cout << "Before sorting: ";
	for(int i=0; i<8; i++)
		cout << arr[i] << " ";
	cout<< endl;

	bubbleSort(arr, 8);

	cout << "After sorting: ";
	for(int i=0; i<8; i++)
		cout << arr[i] << " ";
	cout<< endl;

	return 0;
}