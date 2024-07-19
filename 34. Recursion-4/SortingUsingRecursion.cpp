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

void selectionSort(int* arr, int n){
	if(n == 0 || n == 1)
		return;

	int minIndex = 0, i = 1;
	for(; i<n; i++){
		if(arr[i] < arr[minIndex])
			minIndex = i;
	}
	swap(arr[0], arr[minIndex]);

	return selectionSort(arr+1, n-1);
}

void insertionSort(int* arr, int n){
	if(n <= 1)
		return;

	insertionSort(arr, n-1);

	int i = n-2;
	int temp = arr[n-1];
	
	while (i >= 0 && arr[i] > temp) {
        arr[i + 1] = arr[i];
        i--;
    }
	arr[i+1] = temp;
}

int main(){
	int arr[] = {3, 5, 1, 17, 9, 6, 2, 7};
	
	cout << "Before sorting: ";
	for(int i=0; i<8; i++)
		cout << arr[i] << " ";
	cout<< endl;

	insertionSort(arr, 8);

	cout << "After sorting: ";
	for(int i=0; i<8; i++)
		cout << arr[i] << " ";
	cout<< endl;

	return 0;
}